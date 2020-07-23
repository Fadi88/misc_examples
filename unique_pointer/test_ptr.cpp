#include <iostream>
#include <memory>
#include <vector>
#include <chrono>

class timer
{
public:
    timer(std::string point)
    {
        m_start_point = std::chrono::high_resolution_clock::now();
        m_point = point;
    }

    ~timer()
    {
        auto endclock = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_point).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endclock).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << "time used by : " << m_point << " was : " << ms << " ms" << std::endl;
    }

private:
    std::string m_point;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_point;
};

struct base{
    std::vector<double> m_container;
    base()
    {
        m_container.reserve(10000);
    }
};

void test_raw()
{
    std::unique_ptr<base> test = std::make_unique<base>();
    test->m_container.push_back(42);
}

void test_unique()
{
    base *test = new base();
    
    test->m_container.push_back(42.0);

    delete test;
}


int main()
{
    constexpr int test_number{150000};
    {
        timer obj("unique pointers");
        for (int idx{}; idx < test_number; ++idx)
        {
            test_unique();
        }
    }

    {
        timer obj("raw pointers");
        for (int idx{}; idx < test_number; ++idx)
        {
            test_raw();
        }
    }

    return 0;
}