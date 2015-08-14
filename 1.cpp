#include<iostream>
using namespace std;
int main()
{
	int i,num,tmp;
	int H=1023,L=0;
	int a[1024]={0};
	for(i=0;i<1024;i++)
	{
		a[i]=i;
	}
	cout<<"请输入要查找的数字：";
	cin>>num;
	while(L<H)
	{
		tmp=(L+H)/2;
		if(num==tmp)
		{
			cout<<"找打了！"<<" "<<a[tmp]<<endl;
			break; 
		}
		else if(num>a[tmp])
		{
			L=tmp+1;
		}
		else
		{
			H=tmp-1;
		}
	} 
	return 0;	 
}
