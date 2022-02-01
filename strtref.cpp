//�����嵥8.6 strtref.cpp
//strc ref.cpp -- using structure references
#include <iostream>
#include <string>
struct free_throws
std::string name;
{
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
// partial initializations - remaining members set to 0
	free_throws one ={"Ifelsa Branch", 13, 14};
	free throws two ={"Andor Knott", 10, 16};
	free_throws three ={"Minnie Max", 7, 9};
	free_throws four ={"Whily Looper", 5, 9};
	free throws five = {"Long Long", 6, 14};
	free throws team ={"Throwgoods", 0, 0};
// no initialization
	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
// use return value as argument
	display(accumulate(team, two));
	accumulate(accumulate(team, three),four);
	display(team);
// use return value in assignment
	dup = accumulate(team,five);
	std::cout << "Displaying team:\n";
	display(team);
	std::cout << "Displaying dup after assignment:\n";
	display(dup) ;
	set_pc(four);
// ill-advised assignment
	accumulate(dup,five) = four;
	std::cout << "Displaying dup after ill-advised assignment:\n";
	display(dup);
	return 0;
}

void display(const free_throws & ft)
{
	using std::cout;
	cout << "Name:" << ft.name << '\n';
	cout << " Made: "<< ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}
void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f *float(ft.made)/float(ft.attempts);
	else
		ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
/*���н�����£�
Name:Ifelsa Branch
 Made: 13       Attempts: 14    Percent: 92.8571
Name:Throwgoods
 Made: 13       Attempts: 14    Percent: 92.8571
Name:Throwgoods
 Made: 23       Attempts: 30    Percent: 76.6667
Name:Throwgoods
 Made: 35       Attempts: 48    Percent: 72.9167
Displaying team:
Name:Throwgoods
 Made: 41       Attempts: 62    Percent: 66.129
Displaying dup after assignment:
Name:Throwgoods
 Made: 41       Attempts: 62    Percent: 66.129
Displaying dup after ill-advised assignment:
Name:Whily Looper
 Made: 5        Attempts: 9     Percent: 55.5556
*/
/*
1.����˵��
�ó������ȳ�ʼ���˶���ṹ���󡣱���ǰ��˵�������ָ���ĳ�ʼֵ�ȳ�Ա�٣�
���µĳ�Ա������ֻ��percent����������Ϊ�㡣��һ�������������£�
set_pc(one);
���ں���set_pc()���β�ftΪ���ã����ftָ��one,
����set_pc()�Ĵ������ó�Աone.percent����������ԣ���ֵ���ݲ����У�
����⽫�������õ���one����ʱ�����ĳ�Աpercent��
��һ�ַ�����ʹ��ָ����������ݵ�ַ����Ҫ����Щ��
set pcp(&one);// using pointers instead - &one instead of one
����
void set_pcp(free_throws * pt)
{
	if (pt->attempts != 0)
		pt->percent = 100.0f *float (pt->made)/float (pt->attempts);
	else
		pt->percent = 0;
}
��һ�������������£�
display(one);

����display0��ʾ�ṹ�����ݣ������޸���������������ʹ����һ��const���ò�����
������������ԣ�Ҳ�ɰ�ֵ���ݽṹ�����븴��ԭʼ�ṹ�Ŀ�����ȣ�ʹ�����ÿɽ�ʡʱ����ڴ档

����һ�������������£�

accumulate (team, one);
����accumulateO���������ṹ�����������ڶ����ṹ�ĳ�Աattempts��made��������ӵ���һ���ṹ����Ӧ��Ա�С�
ֻ�޸��˵�һ���ṹ����˵�һ������Ϊ���ã����ڶ�������Ϊconst���ã�
free_throws & accumulate(free_throws & target, const free_throws & source);

����ֵ�أ���ǰ���۵ĺ�������û��ʹ��������Ŀǰ���ԣ�ԭ�����Խ�����ֵ����Ϊvoid�����뿴�����������ã�
display(accumulate(team, two));

����������ʲô��˼�أ����ȣ����ṹ����team��Ϊ��һ���������ݸ���accumulate0��
����ζ���ں���accumulate(0�У�targetָ�����team������accumulate0�޸�team,�ٷ���ָ���������á�
ע�⵽����������£�
return target;

�⿴������䲢����֪�����ص������ã�������ͷ��ԭ��ָ������һ�㣺
free_throws & accumulate(free_throws & target, const free_throws & source)

����������ͱ�����Ϊfree_throws ������free_throws &������������佫���� target��Ҳ���� team���Ŀ�����
����������Ϊ���ã�����ζ�ŷ��ص���������ݸ�accumulateO��team����
����������accumulate(O�ķ���ֵ��Ϊ�������ݸ���display(),����ζ�Ž�team���ݸ���display()��
displayO�Ĳ���Ϊ���ã�����ζ�ź��� display()�е�ftָ����� team,��˽���ʾ team �����ݡ����ԣ��������룺
display (accumulate (team, two));
������Ĵ����Ч��

accumulate (team, two) ;
display(team);
�����߼�Ҳ������������䣺
������
*/