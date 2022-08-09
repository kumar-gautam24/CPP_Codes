#include<iostream>
using namespace std;

void move(int n,char a,char b,char c){
	if(n==0)
		return;
	move(n-1,a,c,b);
	cout<<"Disk "<<n<<" moved from "<<a<<" to "<<c<<endl;
	move(n-1,b,a,c);
}

int main(){
	int n;
	cin>>n;
	move(n,'A','B','C');
	return 0;

}