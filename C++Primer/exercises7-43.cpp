#include <iostream>
class NoDefault{
public :
	NoDefault(int i){std::cout<<"int put i is "<<i<<endl;}
};

class C{
public:
	NoDefault nd;
	C();
};

void main(int argc,char * * argv)
{
	C  c;
	return 0;
}
