#include<iostream>
using namespace std;
class Test
{
public:
	Test();
	Test(const Test&);
	Test(int i, char a)
	{
		m_i = i;
		m_a = a;
	}
	~Test();
	void display()
	{
		cout << m_a << "  " << m_i << endl;
	}

private:
	int m_i;
	char m_a;
};

Test::Test()
{
	m_i = 10;
	m_a = 'A';
	cout << "Ĭ�Ϲ��캯��" << endl;
}
Test::Test(const Test& obj)
{
	m_i = obj.m_i;
	m_a = obj.m_a;
}
Test::~Test()
{
	cout << "��������" << endl;
}
int main()
{
	Test t1(21,'D');
	Test t2=t1;//Ĭ�Ͽ������캯����ʼ��1
	t2.display();
	t2.~Test();
	Test t3(t1);//Ĭ�Ͽ������캯����ʼ��2
	t3.display();
	t3.~Test();
	system("pause");
	return 0;
}