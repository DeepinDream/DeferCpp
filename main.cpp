#include <iostream>
#include "defercpp.h"

using namespace std;

void DeferTest()
{
    DeferCpp abc([]{cout << "Hello Defer" << endl;});
    cout << __FUNCTION__ << " coming" << endl;
}

void DeferTest2()
{
    int count = 1;
    defer(cout << "Hello Defer2" << endl);
    defer(cout << "count = " << count << endl);
    cout << __FUNCTION__ << " coming" << endl;
}

void DeferTest3()
{
    defer(cout << "Hello Defer3" << endl;);
    defer(cout << "Hello Defer3" << endl; cout << "quit" << endl;);
    cout << __FUNCTION__ << " coming" << endl;
}

int DeferTest4()
{
    int ret = 3;
    defer(ret = 0);
    return ret;
}

int DeferTest5(int& ret)
{
    ret = 3;
    defer(ret = 1);
    return ret;
}

class A
{
public:
    int testcount = 1;
    void func()
    {
        defer(cout << "testcount: " << testcount << endl);
        defer(testcount = 3);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    DeferTest();
    DeferTest2();
    DeferTest3();
    A a;
    a.func();
    cout << "DeferTest4 return:  " << DeferTest4() << endl;

    {
        int ret = DeferTest5(ret);
        cout << "DeferTest5 return:  " << ret << endl;
    }

    {
        int ret;
        DeferTest5(ret);
        cout << "DeferTest5 return:  " << ret << endl;
    }

    return 0;
}
