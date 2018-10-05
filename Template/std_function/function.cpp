#include<iostream>
#include<functional>
using namespace std;

template<class T>
class B{
	public:
		std::function<void(const T&)> func;
};
class A{
public:
	void Print() const{cout << "Hello World!" << endl;}

};
int main(){
	A a_obj;    B<A> b_obj;
	
	b_obj.func = &A::Print;
	b_obj.func(a_obj);
}
