#include <iostream>
#include <memory>

void test(std::unique_ptr<int>& uni_ptr)
{
    std::unique_ptr<int> local = std::move(uni_ptr);
    *local = 42;
}

int main()
{
    std::unique_ptr<int> ptr = std::make_unique<int>();

    test(ptr);

    return 0;
}
