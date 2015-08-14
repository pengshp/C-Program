#include<stdio.h>
void main()
{
	int i,n;
	scanf("%d",&n);
	i=2;
	while(i<n)
	{
		if(n%i==0)
		break;
		i++;
	}
	if(i==n)
		printf("YES");
	else
		printf("NO");
}