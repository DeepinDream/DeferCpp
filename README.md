# DeferCpp

实现 Golang defer 功能

使用方法:

```
#include <iostream>
#include "defercpp.h"

void DeferTest()
{
    int count = 1;
    defer(cout << "Hello World" << endl);
}

int main()
{
    DeferTest();
    return 0;
}
```
