#include<iostream>
using namespace std;
class Test
{
public:
	Test();
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

Test::~Test()
{
	cout << "��������" << endl;
}
int main()
{
	Test t1;
	t1.display();
	t1.~Test();
	Test t2(11, 'B');
	t2.display();
	t2.~Test();
	system("pause");
	return 0;
}