#include<iostream>
using namespace std;

class Circle{
	int test=0; //use for access testing
protected:
	double radius; //be protected to let Cylinder constructor access
public:
	Circle(double r=1.0) : radius(r) {;}//constructor
	static float PI;	
	void setR(double r=1.0) {radius=r;}
	double calVol() {return (PI * radius * radius);}
	void showVol() {cout << "radius=" << radius << "\t"; 	//access data member
			cout << "volume=" << calVol() << endl;}	// call member function
};
float Circle::PI = 3.1415;

class Cylinder:public Circle{
	double length;	//add one data member
public:
	Cylinder(double r=1.0, double l=1.0):Circle(r),length(l){;}
	void setRL(double r=1.0,double l=1.0){radius=r;length=l;}
	double calVol(){return Circle::calVol()*length;}
	void display(){cout << "d radius=" << radius << "\t";   //access Circle member
		       cout << "d length=" << length << "\t";   //access own member
		       cout << "d volume=" << calVol() << endl;}//call own member function
};
int main(){
	Circle cr1 ,cr2(4);
	Cylinder cy1, cy2(10,20);

	cout << "PI = "  << Circle::PI << endl;	
	
	cr1.setR(3); 
	cr1.showVol(); cr2.showVol(); 
	cy1.setRL(2,3);
	cy1.showVol(); cy1.display();
	cy2.showVol(); cy2.display();
	
	//cout << cr1.test << endl;  //error base class object can not access private member
	//cout << cy1.test << endl;  //base class private member is inaccessible for derived class 
	return 0;
}

