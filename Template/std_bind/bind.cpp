#include<iostream>
#include<functional>
using namespace std;

class A{
	public:
		void Print(){cout << "Hello World!"<< endl;}
		void foo(int){cout << "Hello C++!" << endl;};
};

void test(){cout << "This is a test function!" << endl;}

void call(function<void()>fun){
	fun();
}

int main(){

	A a;
	function<void()> func = bind(&A::Print,a);
	func();	 // a.Print()
	function<void()> func1 = bind(&A::foo,a,6);
	func1(); // a.foo(6)
 
	call(&test);	// test()
	call(bind(&A::Print, a)); //a.Print()
	call(bind(&A::foo ,a ,10)); //a.foo(10)

	return 0;
}

