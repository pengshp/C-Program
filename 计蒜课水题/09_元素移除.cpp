#include<iostream>
using namespace std;
int main()
{
	int n,i,elem;
	int len;
	int A[100] = { 0 };
	cin >> n;
	len = n;
	for (i = 0; i < n;i++)
	{
		cin >> A[i];
	}
	cin >> elem;
	for (i = 0; i < n;i++)
	{
		if (A[i]==elem)
		{
			len--;
			//A[i] = A[i + 1];
		}
		//A[i + 1] = A[i + 2];
	}
	cout << len << endl;
	system("pause");
	return 0;
}