#include<iostream>
using namespace std;
int fan(int num)
{
	int num,lastres=0;
	lastres *=10;    //0    50   540  5430 54320
	wei=num%10;      //5    4    3    2    1
	lastres +=wei;   //5    54   543  5432 54321
	num /=10;        //1234 123  12   1    0
	return lastres;
}
int main()
{
	cout<<"请输入数字num:";
	cin>>num;
	if(num>0&&num<10)
	{
		return num;
	}
	else
	{
		return fan(num-1)+fan(num-2);
	}
	cout<<num<<" "<<"反序后："<<fan(num)<<endl;
	return 0;
}
