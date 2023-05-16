#include <thread>
#include <chrono>
#include <iostream>

int maxClient = 5;

void client(int& load) {
    while (load < maxClient) {
        ++load;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << load << " +1 Client\n";
    }
}

void orerationist(int& load) {
    while (load > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        --load;
        std::cout << load << " -1 Client\n";
    }
}


int main()
{
    int load = 0;
    
    std::thread t1(client, std::ref(load));
    std::thread t2(orerationist, std::ref(load));
    t1.detach();
    if (t2.joinable()) t2.join();
    std::cout << "All clients are served";
}
