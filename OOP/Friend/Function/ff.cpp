#include<iostream>
using namespace std;
class CPoint{
	int x,y;
	friend CPoint offset(CPoint &,int);
public:
	CPoint(){x=0;y=0;} //constructor
	CPoint(int a, int b){x=a; y=b;}
	void Print(){
		cout << x << " " << y << endl;
	}
};
CPoint offset(CPoint &pt, int diff){ //shift  pt => reference
	pt.x += diff;
	pt.y += diff;
	return pt;
}
int main(){
	CPoint p1(3,6);
	p1.Print();
	offset(p1,4); //friend function
	p1.Print();
}
