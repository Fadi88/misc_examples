#include <iostream>

void test(int *raw_ptr)
{
    *raw_ptr = 42;

    delete raw_ptr;
}

int main()
{
    int *ptr = new int;

    test(ptr);
    return 0;
}
