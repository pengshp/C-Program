#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int i;
	char arr1[50],arr2[50],array;
	cin>>arr1>>arr2;
	for (int i = 0; i < arr1.size(); i++)
	{
		if (arr1[i]==arr2[i])
		{
			array[i]='1';
		}
		else
			array[i]='0';
	}
	cout<<array<<endl;
	return 0;
}