#include <iostream>

using namespace std;

int fibonacci(int n){
	if(n==0 || n==1)
		return 1;
	else{
		return fibonacci(n-2)+fibonacci(n-1);
	}
}

int main(){
    int num,res;
	cout<<"Ingrese su numero: ";
	cin>>num;
	for(int i=2;i<num;i++){
		res=fibonacci(i);
		cout<<res<<endl;
	}
}
