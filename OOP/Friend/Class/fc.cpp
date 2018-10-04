#include<iostream>
using namespace std;
class CPoint{
	friend class CLine;
	int x,y;
	void Offset(int diff){x+=diff; y+=diff;}
public:
	CPoint(){x=0; y=0;};
	CPoint(int a,int b){x=a; y=b;} //constructor
	void Print(){cout << x << " " << y << endl;}
};
class CLine{
	CPoint p1,p2;			//create CPoint object
public:
	CLine(int x, int y, int w, int z){
		p1.x=x; p1.y=y;		//access friend class private data
		p2.x=w; p2.y=z;
	}
	void offset(int x,int y){	//call CPoint::Offset
		p1.Offset(x);
		p2.Offset(y);
	}
	void Print(){
		cout << "Point1:";
		p1.Print();
		cout << "Point2:";
		p2.Print();		//call friend class public member function
	}
	void Display(){
		p1.Offset(100);
		p2.Offset(200);		//call friend class private member function
		p1.Print();		
		p2.Print();
	}
};
int main(){
	CPoint p1(2,4);
	p1.Print();
	//p1.Offset(3) error; private function
	CLine l1(1,3,5,7), l2(2,4,6,8);
	//l1.Offset(50);  error cannot find the member
	l1.offset(10,10);
	l1.Print();
	l2.Display();
	return 0;
}
