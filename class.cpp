#include<iostream>
using namespace std;
class Test
{
public:
	Test(int x,int y)
	{
		m_x=x;
		m_y=y;
	}
	//~Test();
	void print()
	{
		cout<<m_x<<" "<<m_y <<endl;
	}
private:
	int m_x;
	int m_y;
};
int main()
{
	Test t1(2,3);
	t1.print();
	cout<<"hello word!"<<endl;
	return 0;
}