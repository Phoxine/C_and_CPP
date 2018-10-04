#include<iostream>
using namespace std;

#ifndef SIZE
#define SIZE 30
#endif

template<class T=int, int MAXSIZE=SIZE>
class Stack{
	T elems[MAXSIZE];
	int top;
public:
	Stack(){top=0;} //constructor
	bool empty(){return top ==0 ;} 
	bool full() {return top == MAXSIZE;}
	void push(T e){
		if(top == MAXSIZE){cout << "full"; return;}
		elems[top++] = e;
	}
	T pop(){
		if (top <=0) {cout << "empty" ; exit(-1);}
		top--;
		return elems[top];
	}
};
template <class T, int MAXSIZE>
void ShowStack(Stack<T,MAXSIZE> &stack){
	while (!stack.empty()){
		cout << stack.pop() << " ";
	}
	cout << endl;
}

int main(){
	Stack<> stack; //use default
	for (int i=10 ; i>0 ; --i){
		stack.push(i);
	}
	ShowStack(stack);
	cout <<"The max size of stack is: "<<SIZE << endl;
	cout << "This is line " << __LINE__ << endl;
}
