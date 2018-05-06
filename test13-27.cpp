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
	 //���巨��  ���������죬������������ֵ���������Աֵ���ݹ���
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
		++*obj.count;  //const �����������ǿ��ڴ����������ã���obj�е�ָ��ָ�����ֵ���޸ģ�����const���ڴ������У�
		if (ps != NULL)
		{
			--*count;
			if (*count == 0)
			{
				delete ps;		//���ڿ�����ֵ�������˵�����پɵĿռ�  ��������Ϊ�������쳣��ȫ��������Ҳ�����˴����Ը�ֵ��״̬
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