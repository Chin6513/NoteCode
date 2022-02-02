//程序清单8.6 strtref.cpp
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
/*运行结果如下：
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
1.程序说明
该程序首先初始化了多个结构对象。本书前面说过，如果指定的初始值比成员少，
余下的成员（这里只有percent）将被设置为零。第一个函数调用如下：
set_pc(one);
由于函数set_pc()的形参ft为引用，因此ft指向one,
函数set_pc()的代码设置成员one.percent。就这里而言，按值传递不可行，
因此这将导致设置的是one的临时拷贝的成员percent。
另一种方法是使用指针参数并传递地址，但要复杂些：
set pcp(&one);// using pointers instead - &one instead of one
……
void set_pcp(free_throws * pt)
{
	if (pt->attempts != 0)
		pt->percent = 100.0f *float (pt->made)/float (pt->attempts);
	else
		pt->percent = 0;
}
下一个函数调用如下：
display(one);

由于display()显示结构的内容，而不修改它，因此这个函数使用了一个const引用参数。
就这个函数而言，也可按值传递结构，但与复制原始结构的拷贝相比，使用引用可节省时间和内存。

再下一个函数调用如下：

accumulate (team, one);
函数accumulate()接收两个结构参数，并将第二个结构的成员attempts和made的数据添加到第一个结构的相应成员中。
只修改了第一个结构，因此第一个参数为引用，而第二个参数为const引用：
free_throws & accumulate(free_throws & target, const free_throws & source);

返回值呢？当前讨论的函数调用没有使用它；就目前而言，原本可以将返回值声明为void，但请看下述函数调用：
display(accumulate(team, two));

上述代码是什么意思呢？首先，将结构对象team作为第一个参数传递给了accumulate()。
这意味着在函数accumulate()中，target指向的是team。函数accumulate()修改team,再返回指向它的引用。
注意到返回语句如下：
return target;

光看这条语句并不能知道返回的是引用，但函数头和原型指出了这一点：
free_throws & accumulate(free_throws & target, const free_throws & source)

如果返回类型被声明为free_throws 而不是free_throws &，上述返回语句将返回 target（也就是 team）的拷贝。
但返回类型为引用，这意味着返回的是最初传递给accumulate()的team对象。
接下来，将accumulate()的返回值作为参数传递给了display(),这意味着将team传递给了display()。
display()的参数为引用，这意味着函数 display()中的ft指向的是 team,因此将显示 team 的内容。所以，下述代码：
display (accumulate (team, two));
与下面的代码等效：

accumulate (team, two) ;
display(team);
上述逻辑也适用于如下语句：
待续
*/
