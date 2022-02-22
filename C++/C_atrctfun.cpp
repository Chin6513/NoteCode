//strctfun.cpp -- functions with a structure argument
#include<iostream>
#include<cmatch>

//structure declaratoins
struct polar
{
	double distance;	//distance from origin
	double angle;		//direction from origin
};
struct rect
{
	double x;	//horizontal distance from origin
	double y;	//vertical distance from origin
};

//prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;
	
	cout<<"Enter the x and y values: ";
	while(cin>>rplace.x>>rplace.y)	//slick use of cin
	{
		pplace= rect_to_polar(rplace);
		show_polar(pplace);
		cout<<"Next two number (q to quit): ";
	}
	cout<<"Done.\n";
	return 0;
}

//convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;
	
	answer.distance=sqrt(xypos.x*xypos.x+xypos.y*xypos.y);
	answer.angle=atan2(xypos.y,xypos.x);
	return answer;	//returns a polar structure
}

//show polar corrdinates, converting angle to degrees
void show_polar(polar dapos)
{
	using namespace std;
	const double Rad_to_deg=57.29577951;
	
	cout<<"distance = "<<dapos.distance;
	cout<<", angle = "<<dapos.angle * Rad_to_deg;
	cout<<"degrees\n";
}
/*通过函数的返回类型和参数，将其设置为不同的结构体，
 *就可以达到不同类型的结构体之间相互转换的效果*/
