#include<iostream>
using namespace std;
int mian()
{
	int i,num,tmp;
	int H=1023,L=0;
	int a[1024];
	for(i=0;i<1024;i++)
	{
		a[i]=i;
	}
	cout<<"������Ҫ���ҵ����֣�";
	cin>>num;
	while(L<H)
	{
		tmp=(L+H)/2;
		if(num==tmp)
		{
			cout<<"�Ҵ��ˣ�"<<" "<<a[tmp]<<endl;
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