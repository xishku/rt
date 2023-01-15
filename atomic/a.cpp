#include <iostream>
#include <atomic>


int main()
{
	std::atomic<int> i = 0;
	++i;
	std::cout << "i=" << i << std::endl;
	return 0;
}


