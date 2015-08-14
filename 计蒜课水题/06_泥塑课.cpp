
#include<iostream>
#include<string>
using namespace std;
struct Student
{
	int a, b, c,V;
	string name;
};
int main()
{
	Student arr[10];
	int i, n, ave, sum=0;
	int x = 0, y = 0;
	do 
	{
		cin >> n;
		if (n==-1)
		{
			break;
		}
		else
		{
			for (i = 0; i < n;i++)
			{
				cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].name;
				arr[i].V = arr[i].a*arr[i].b*arr[i].c;
				sum += arr[i].V;
			}
			ave = sum / n;
			for (i = 0; i < n;i++)
			{
				if (arr[i].V>ave)
				{
					x = i;
				}
				else if (arr[i].V<ave)
				{
					y = i;
				}
			}
		}
	} while (n!=-1);
	cout << arr[x].name << " took clay from " <<arr[y].name << endl;
	system("pause");
	return 0;
}


#include <stdio.h>  

int main()
{
	//M为行数，N为列数，Mode为上下(0)/左右(1)模式的选择
	int m, n, mode;
	int i, j;
	int before[200][200] = { 0 }, after[200][200] = { 0 };
	scanf("%d%d%d", &m, &n, &mode);
	//input  
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &before[i][j]);
	//change  
	if (mode == 0)  //模式选择  
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		after[i][j] = before[i][n - j - 1];
	else
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		after[i][j] = before[m - i - 1][j];
	//output  
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++)
			printf("%d ", after[i][j]);
		printf("\n");
	}
	return 0;
}
