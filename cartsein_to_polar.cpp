//program to convert cartesin to polar co-ordinate
#include<iostream>
#include<cmath>
using namespace std;
 
class solution{
	public:
	void solve(int x,int y)
	{
	//x=rcos(theta)
	//r=sqrt(x^2+y^2); and thetha=tan-(x/y);
	float r,thetha;
	r=sqrt(x*x+y*y);
	thetha=atan2(x,y);
	cout<<r<<" "<<thetha;

	}
};

int main(){
	solution ob;
	int x,y;
	cin>>x>>y;
	ob.solve(x,y);
	return 0;
}