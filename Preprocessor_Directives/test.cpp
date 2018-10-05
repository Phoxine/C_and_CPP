#include<iostream>
using namespace std;

int main(){
#ifndef MAX
#define MAX 10
int A[MAX];
#undef MAX
#endif 

#ifndef MAX
#define MAX 20
char B[MAX];
#undef MAX
#endif
cout << sizeof(A)<< endl << "this code is at " << __LINE__ 
     << " line and the file name is "<< __FILE__ << endl;
cout << sizeof(B)<< endl << "Compile date and time: " 
     << __DATE__ <<"\t"<< __TIME__ << endl;
cout << "__cplusplus:" <<__cplusplus << endl;

}
