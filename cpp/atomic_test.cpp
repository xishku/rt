#include "atomic_test.h"

#include <iostream>
#include <thread>
#include <memory>
#include <vector>


long long MyCalc::SumInt(int num)
{
    for (int i = 0; i <= num; i++) {
        sum_ += i;
    }

    std::cout << "sum_ = " << sum_ << std::endl;
    return 0;
}

void MyCalc::ThdTest(int i, int num)
{
    std::cout << "print in thread " << i  << " num = " << num << std::endl;
    SumInt(num);
}

long long MyCalc::ThdSumInt(int num)
{
    std::vector<std::shared_ptr<std::thread>> thds;
    for (int i = 0; i < 10; i++) {
        thds.push_back(std::make_shared<std::thread>(&MyCalc::ThdTest, this, i, num));
    }

    for (auto thd : thds) {
        thd->join();
    }

    return sum_;
}

