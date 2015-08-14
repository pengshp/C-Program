#include<iostream>
using namespace std;
int main()
{
	int num,wei;
	cout<<"ÇëÊäÈëÊı×Önum:";
	cin>>num;
	int lastres=0;
	while(num)           //num=12345 
	{                    //1    2    3    4    5
		lastres *=10;    //0    50   540  5430 54320
		wei=num%10;      //5    4    3    2    1
		lastres +=wei;   //5    54   543  5432 54321
		num /=10;        //1234 123  12   1    0
	}
	cout<<lastres<<endl;
	return 0;
}
