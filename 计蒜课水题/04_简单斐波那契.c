#include<stdio.h>
#include <stdlib.h>
int fun(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fun(n - 1) + fun(n - 2);
}
int main(void)
{
	int n, i = 0;
	scanf("%d", &n);
	if (n >= 1)

		printf("%d\n", fun(n));
	else
		printf("输入错误！请重新输入......\n");
	return 0;
}