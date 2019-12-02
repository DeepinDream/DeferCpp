# DeferCpp

实现 Golang defer 功能

使用方法:

```
#include <iostream>
#include "defercpp.h"

using namespace std;

void DeferTest()
{
    defer(cout << "Hello Defer" << endl);
    cout << "Hello World" << endl;
}

int main()
{
    DeferTest();
    return 0;
}
```
