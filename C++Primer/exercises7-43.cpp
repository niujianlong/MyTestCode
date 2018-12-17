#include <iostream>
#include "common.h"
using namespace std;
class NoDefault
{
  public:
	NoDefault(int i) { cout << "int put i is " << i << endl; }
};

class C
{
  public:
	C() : nd(1) { cout << "C default constructed function" << endl; }

  private:
	NoDefault nd;
};

int main(int argc, char **argv)
{
	C c;
	Sales_data sd;
	string s = "99-90-99999";
	Sales_data item1(s);
	Sales_data item2("999-90-9999");//这种无论是加还是不加explicit都行
	Sales_data item3 = s; //这种在加了explicit情况下是不行的
	//Sales_data &item4 = s;  //error
	const Sales_data &item5 = s;
	//sd.combine(s);
	//sd.combine1(s);
	cout<<sd<<endl;
	//sd.combine2(s);
	return 0;
}
