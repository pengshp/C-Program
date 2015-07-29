#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>       //包含strcpy 
#include<stdlib.h>      //包含malloc,free 
using namespace std;
class Test
{
public:
	Test()
	{
		a = 10;
		p = (char *)malloc(100);
		strcpy(p, "apappap");
		cout << "我是构造函数" << endl;
	}
	void print()
	{
		cout << a << endl;
		cout << p << endl;
	}
	~Test()
	{
		if (p != NULL)
		{
			free(p);
		}
		cout << "我是析构函数" << endl;
	}
protected:
private:
	int a;
	char *p;
};
void display()
{
	Test t1;         //先创建的对象后释放
	t1.print();
	cout << "-----------" << endl;
	Test t2;
	t1.print();
}
int main()
{
	display();
	system("pause");
	return 0;
}