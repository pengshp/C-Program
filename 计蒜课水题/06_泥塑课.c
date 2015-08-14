#include<stdio.h>
typedef struct students{ int len; int wid; int hei; char name[20]; }Stu;

int main()
{
	Stu stu[10];
	int n, max, min;//n_max,n_min;
	do
	{
		scanf("%d\n", &n);
		if (n == -1)break;
		max = 0;
		min = 0;
		for (int i = 0; i<n; i++)
		{
			scanf("%d %d %d %s", &stu[i].len, &stu[i].wid, &stu[i].hei, &stu[i].name);
			if (stu[i].len*stu[i].wid*stu[i].hei>stu[max].len*stu[max].wid*stu[max].hei)
			{
				//max=stu[i].len*stu[i].wid*stu[i].hei;
				max = i;
			}
			if (stu[i].len*stu[i].wid*stu[i].hei < stu[min].len*stu[min].wid*stu[min].hei)
			{
				//min=stu[i].len*stu[i].wid*stu[i].hei;
				min = i;
			}
		}
		printf("%s took clay from %s\n", stu[max].name, stu[min].name);
	} while (n != -1);
	return 0;
}