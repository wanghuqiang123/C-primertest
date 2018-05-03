#include<iostream>
#include<string>
using namespace std;

class HasPtr
{
private:
	int i;
	string *ps;
public:    
	 //���巨��  ���������죬������������ֵ���������Աֵ���ݹ���
	HasPtr()
	{

	}
	HasPtr(const HasPtr& obj):ps(new string(*obj.ps)),i(obj.i)
	{
		//copy allocator
	}
	HasPtr(const string& s)
	{
		i = 0;
		ps = new string(s);
	}
	HasPtr& operator=(const HasPtr& obj)
	{
		auto temp = new string(*obj.ps);
		if (ps != NULL)
		{
			delete ps;		//���ڿ�����ֵ�������˵�����پɵĿռ�  ��������Ϊ�������쳣��ȫ��������Ҳ�����˴����Ը�ֵ��״̬
			ps = temp;
		}
		else 
		{
			ps = temp;
		}
		i = obj.i;

		return *this;
	}
	HasPtr& operator=(const string& s)
	{
		*ps = s;
		i = 0;
	}
	~HasPtr()
	{
		delete ps;
	}
	void _print()const
	{
		cout << "string is:" << *ps << "i is :" << i << endl;
	}
};

int main()
{
	HasPtr p("wang");
	HasPtr p1 = p;
	HasPtr p2;
	p2 = p;
	p._print();
	p1._print();
	p2._print();
	return 0;
}