#include<iostream>
#include<string>
using namespace std;

class Student
{
	public:
	Student();
	Student(string _name)
	{
		m_strName=_name;
	}
	Student(const Student& stu);
	~Student()
	{
		cout<<"Îö¹¹º¯Êı"<<endl;
	}
	void setName(string _name)
	{
		m_strName=_name;
	}
	string getName()
	{
		return m_strName;
	}
	private:
	string m_strName;
}

int main()
{
	Student *stu=new Student();
	stu->setName("Ä½¿ÎÍø");
	cout<<stu->getName()<<endl;
	delete stu;
	return 0;
}