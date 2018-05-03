#include<iostream>
#include<string>
using namespace std;

class HasPtr
{
private:
	int i;
	string *ps;
public:    
	 //三五法则  （拷贝构造，析构，拷贝赋值运算符）成员值传递构造
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
			delete ps;		//对于拷贝赋值运算符来说，销毁旧的空间  这样做事为了做到异常安全，这样做也做到了处理自赋值的状态
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