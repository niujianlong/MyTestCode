#include <iostream>
using namespace std;
class NoDefault{
public :
	NoDefault(int i){cout<<"int put i is "<<i<<endl;}
};

class C{
public:
	C(){cout<<"C default constructed function"<<endl;}
private:
	NoDefault nd;	
};

int main(int argc,char * * argv)
{
	C  c;
	return 0;
}
