#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std::chrono_literals;
std::atomic<int> clientsCount = 1;

void clientsThread() {
	while (clientsCount != 10) {
		//std::this_thread::sleep_for(1000ms);
		++clientsCount;
		std::cout << "clientsCount from clientsThread: " << clientsCount << "\n";
	}
}

void operatorTread() {
	while (clientsCount != 0) {
		//std::this_thread::sleep_for(2000ms);
		--clientsCount;
		std::cout << "clientsCount from operatorTread: " << clientsCount << "\n";
	}

}
int main() {
	std::thread t1(clientsThread);
	std::thread t2(operatorTread);
	t1.join();
	t2.join();
	return 0;
}