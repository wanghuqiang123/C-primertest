#include<iostream>
#include<string>
using namespace std;

class Empolyee
{
private:
	static int a;
	struct
	{
		int number;
		string name;
	}data;
public:
	Empolyee()
	{
		data.number = ++a;
	}
	Empolyee(const string& s)
	{
		data.number = ++a;
		data.name = s;
	}
	//�������캯�������巨��
	Empolyee(const Empolyee& obj)  //�ϳɵĿ������캯������ȥ����ţ�ֻ��򵥵ĸ���
	{
		this->data.name = obj.data.name;
		this->data.number = ++a;
	}
	Empolyee& operator=(const Empolyee& obj) //��ֵ�������������
	{// ͬ������
		this->data.name = obj.data.name;
		return *this;
	}
	const string& name()const
	{
		return this->data.name;
	}
	int number()const
	{
		return this->data.number;
	}
	~Empolyee()
	{

	}
};
int Empolyee::a = 0;

void _print(const Empolyee& e)
{
	cout << e.name() <<" number is: "<<e.number()<< endl;
}
int main()
{
	Empolyee a("jason");
	Empolyee b = a , c;
	c = b;
	_print(a);
	_print(b);
	_print(c);
	
	return 0;
}