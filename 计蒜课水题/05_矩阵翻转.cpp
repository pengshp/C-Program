#include<iostream>
using namespace std;
int main()
{
	int m,n,t,i,j;
	cin>>m>>n>>t;
	int arr1[200][200]={0},arr2[200][200]={0};
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr1[i][j];
			if(t==0)
			{
				arr2[i][j]=arr1[i][n-1-j];
			}
			else if(t==1)
			{
				arr2[i][j]=arr1[m-1-i][j];
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<arr2[i][j];
		}
		cout<<endl;
	}
	return 0;
}