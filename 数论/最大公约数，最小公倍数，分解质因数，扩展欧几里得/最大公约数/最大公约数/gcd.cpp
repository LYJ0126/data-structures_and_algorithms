#include<iostream>
#include<cmath>
using namespace std;

int gcd1(int x, int y)//µÝ¹éÐ´·¨
{
	if(x==0) return y;
	else return gcd1(y%x,x);
}
int gcd2(int x, int y)//·ÇµÝ¹éÐ´·¨
{
	while (x != 0)
	{
		int t=x;
		x=y%x;
		y=t;
	}
	return y;
}
int main()
{
	int x,y;
	cin>>x>>y;
	cout<<gcd1(x,y)<<endl;
	cout<<gcd2(x,y)<<endl;
	return 0;
}