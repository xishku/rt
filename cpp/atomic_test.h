#include <atomic>

class MyCalc {
public:
    long long SumInt(int num);
    long long ThdSumInt(int num);
    void ThdTest(int i, int num);

private:
    std::atomic<long long> sum_ {0};
    // long long sum_ {0};
};




