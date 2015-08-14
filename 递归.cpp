#include<iostream>
using namespace std;
double go(double n)
{
	if (n==1)
	{
		return 1.0;
	}
	else if(n==2)
	{
		return 2.0;
	}
	else
	{
		return go(n-1)+go(n-2);
	}
}
int main()
{
	double n;
	cout<<"ÇëÊäÈë½×Êý£º"; 
	cin>>n;
	cout<<go(n)<<endl;
	return 0;
} 
