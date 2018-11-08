#include <iostream>
using namespace std;
#include "dictree.h"
int main()
{
    DicTree t;
    t.Add("HELLO");
    t.Add("HI");
    t.Add("BYE");
    t.Add("BOY");
    t.Add("S");
    cout<<t.Search("BOYS")<<endl;
    cout<<t.Search("NOW")<<endl;
    return 0;
}
