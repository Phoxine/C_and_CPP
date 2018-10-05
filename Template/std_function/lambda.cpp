#include<iostream>
#include<functional>
using namespace std;
int main(){
	function<void()> fun = [](){cout << "hello world!" << endl;};
	fun();
}
