#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>       //����strcpy 
#include<stdlib.h>      //����malloc,free 
using namespace std;
class Test
{
public:
	Test()
	{
		a = 10;
		p = (char *)malloc(100);
		strcpy(p, "apappap");
		cout << "���ǹ��캯��" << endl;
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
		cout << "������������" << endl;
	}
protected:
private:
	int a;
	char *p;
};
void display()
{
	Test t1;         //�ȴ����Ķ�����ͷ�
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