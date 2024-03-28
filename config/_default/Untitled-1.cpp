#include <iostream>
using namespace std;
int main()
{
    int a;
    int &b=a;
    b=10;
    cout<<"a="<<a<<endl;
    
    return 0;
}
