//本程序将令Sales_data类支持与sales_item类完全一样的操作集合
//Sales_data的接口应该包括以下操作
//一个isbn成员函数，用于返回对象的ISBN编号
//一个combine成员函数，用于将一个Sales_data对象加到另一个对象上
//接口函数
//一个add的函数，执行两个Sales_data对象的加法
//一个read函数，将数据从istream读入到Sales_data对象中
//一个print函数，将Sales_data对象的值输出到ostream中

#ifndef SALES_DATA_H
#define SALES_DATA_H
 
#include<iostream>
#include<string>
using namespace std;
class Sales_data
{
private:
	string bookno;//书号
	double units_sold;//销售出的册数
	double price;//单本售价
	double revenue;//总销售额
	double average;
 
public:
	Sales_data();//声明一个无参的构造函数
	//explicit Sales_data(string &s,double price=0):bookno(s){}   //这里就是一个隐式转换的构造函数
	//explicit Sales_data(string b, int u, double p) :bookno(b), units_sold(u), price(p){}//声明一个有参数的默认构造函数，用参数的初始化表对数据成员初始化
	 Sales_data(const string &s){}
	friend istream& operator >> (istream &, Sales_data &);//运算符>>重载为友元函数
	friend ostream& operator << (ostream &, Sales_data &);//运算符<<重载为友元函数
	friend Sales_data operator + (Sales_data & lhs, Sales_data & rhs);//声明有元的运算符重载 + 函数
	Sales_data& operator = (const Sales_data &);//重载赋值运算符
	friend bool operator == (Sales_data &, Sales_data &);//声明有元的重载双目运算符==函数
	Sales_data & operator += (const Sales_data &);//声明一个返回sales_item类型的重载运算符+=函数，形参采用常量引用
	double avg_price();
	string isbn() const;//声明isbn函数，并返回书籍号
	//一个combine成员函数，用于将一个Sales_data对象加到另一个对象上
	Sales_data& combine(const Sales_data &);
	Sales_data& combine1(Sales_data &);
	Sales_data& combine2(Sales_data);
	//声明Sales_data类的非成员接口函数
	//一个read函数，将数据从istream读入到Sales_data对象中
	friend istream & read(istream &,Sales_data &);//声明一个read函数，函数返回类型为istream &
	//一个add的函数，执行两个Sales_data对象的加法
	friend Sales_data add(const Sales_data &, const Sales_data &);
 
};
Sales_data::Sales_data()//定义无参数的构造函数
{
	bookno = "null";
	units_sold = 0;
	price = 0.0;
}
 
istream& operator >>(istream &input, Sales_data &s)//对重载运算符>>进行定义
{
	input >> s.bookno >> s.units_sold >> s.price;
	if (input)
	{
		s.revenue = s.units_sold * s.price;
	}
	return input;
}
ostream& operator << (ostream &output, Sales_data &s)//对重载运算符<<进行定义
{
	//output << s.bookno << " "<< s.units_sold << " " << s.revenue << " " << s.price << endl;
	output << s.bookno << " " << s.units_sold << " " << s.revenue << " " << s.avg_price() << endl;
	return output;
}
//将两个sales_item对象相加时，程序应该检测其两个对象的isbn书号是否相同
Sales_data operator + (Sales_data & lhs, Sales_data & rhs)//定义重载运算符+函数,lhs和rhs是sales_item的对象
{
	Sales_data ret;
	ret.bookno = lhs.bookno;
	ret.units_sold = lhs.units_sold + rhs.units_sold;
	ret.revenue = lhs.revenue + rhs.revenue;
	ret.avg_price();
	return ret;
}
bool operator == (Sales_data &lhs, Sales_data &rhs)
{
	return lhs.units_sold == rhs.units_sold && lhs.price == rhs.price && lhs.isbn() == rhs.isbn();
}
Sales_data& Sales_data:: operator = (const Sales_data &lhs)//重载赋值运算符=
{
	bookno = lhs.bookno;
	units_sold = lhs.units_sold;
	price = lhs.price;
	return *this;
}
Sales_data& Sales_data ::operator += (const Sales_data &rhs)//
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;//将this对象作为左值返回,*this相当于一个sales_item对象
}
double Sales_data::avg_price()
{
	average = revenue / units_sold;
	return average;
}
string Sales_data::isbn() const 
{
	return bookno;
}
//一个combine成员函数，用于将一个Sales_data对象加到另一个对象上
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
istream & read(istream &input, Sales_data &rhs)//声明一个read函数，将数据从istream读入到Sales_data对象中
{
	input >> rhs.bookno >> rhs.units_sold >> rhs.price;
	rhs.revenue = rhs.units_sold * rhs.price;
	return input;
}
 
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)//一个add的函数，执行两个Sales_data对象的加法
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	sum.avg_price();
	return sum;
}

Sales_data& Sales_data::combine1(Sales_data &)
{

}
Sales_data& Sales_data::combine2(Sales_data)
{

}
#endif