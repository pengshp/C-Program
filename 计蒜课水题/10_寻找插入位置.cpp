#include<iostream>
using namespace std;
int searchInsert(int A[], int n, int target)
{
	int i;
	for (i = 0; i < n;i++)
	{
		if (A[i]==target)
		{
			return i;
		}
		else if (target>A[i])
		{
			return i +1;
		}
	}
}
int main()
{
	int n, target;
	int A[100] = { 0 };
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> A[i];
	}
	cin >> target;
	cout << searchInsert(A,n,target) << endl;
	system("pause");
	return 0;
}