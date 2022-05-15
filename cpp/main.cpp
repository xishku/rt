#include <iostream>
#include <thread>
#include <cstdint>
#include <csignal>
#include <ctime>


static bool g_running = true;

int64_t TimeDiffInNs(struct timespec *pre, struct timespec *now)
{
    return (now->tv_sec - pre->tv_sec) * 1e9 + now->tv_nsec - pre->tv_nsec;
}

void Loop()
{
    static const int PERIOD_IN_US = 1000;
    static const int PERIOD_IN_US_2_NS = 1000;
    static const int LOG_CIRCLE = 1000;
    int64_t count = 0;

    struct timespec init;
    clock_gettime(CLOCK_MONOTONIC, &init);

    bool print = false;
    while (true) {
        if (!g_running) {
            break;
        }

        ++count;
        print = (count % LOG_CIRCLE == 0);

        struct timespec pre;
        clock_gettime(CLOCK_MONOTONIC, &pre);

        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);
        if (print) {
            printf("count=%ld duration=%luns\n", count, TimeDiffInNs(&pre, &now));
        }

        int64_t sleepTimeInUs = (count * PERIOD_IN_US * PERIOD_IN_US_2_NS - TimeDiffInNs(&init, &now))
            / PERIOD_IN_US_2_NS;
        if (sleepTimeInUs <= 0) {
            printf("count=%ld time passed sleepTime=%ld\n", count, sleepTimeInUs);
            continue;
        }

        usleep(sleepTimeInUs);
    }
}

void Stop(int s)
{
    g_running = false;
}

int main()
{
    signal(SIGINT, &Stop);
    Loop();

    std::thread rtThread(Loop);
    rtThread.join();
    printf("thread join ok!\n");

    return 0;
}