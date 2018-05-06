#include<iostream>
#include<string>
using namespace std;

class HasPtr
{
private:
	int i; 
	string *ps;
	size_t *count;
public:    
	 //三五法则  （拷贝构造，析构，拷贝赋值运算符）成员值传递构造
	HasPtr()
	{
		ps = NULL;
		i = 0;
		count = NULL;
	}
	HasPtr(const HasPtr& obj):ps(obj.ps),i(obj.i)
	{
		count = obj.count;
		++*count;
	}
	HasPtr(const string& s)
	{
		i = 0;
		ps = new string(s);
		count = new size_t(1);
	}
	HasPtr& operator=(const HasPtr& obj)
	{
		++*obj.count;  //const 对它所属的那块内存区域起作用，而obj中的指针指向的数值被修改，不在const的内存区域中；
		if (ps != NULL)
		{
			--*count;
			if (*count == 0)
			{
				delete ps;		//对于拷贝赋值运算符来说，销毁旧的空间  这样做事为了做到异常安全，这样做也做到了处理自赋值的状态
				delete count;
			}
			ps = obj.ps;
			count = obj.count;
		}
		else 
		{
			ps = obj.ps;
			count = obj.count;
		}
		i = obj.i;

		return *this;
	}
	HasPtr& operator=(const string& s)
	{
		if (ps != NULL)
		{
			--*count;
				if(*count == 0)
				{
					delete ps;
					delete count;
				}
				ps = new string(s);
				count = new size_t(1);
		}
		else
		{
			ps = new string(s);
			count = new size_t(1);
		}
		i = 0;
		return *this;
	}
	~HasPtr()
	{
		--*count;
		if (*count == 0)
		{
			delete ps;
			delete count;
		}
	}
	void _print()const
	{
		cout << "string is:" << *ps << " count is : " << *count << endl;
	}
};

int main()
{
	HasPtr p("aaaa");
	HasPtr p1 = p;
	HasPtr p2;
	p2 = p;
	p2 = "bbbb";
	
	p._print();
	p1._print();
	p2._print();
	return 0;
}