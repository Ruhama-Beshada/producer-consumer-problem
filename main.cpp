// Producer Consumer Problem
// One Producer, One Consumer, N-sized Buffer
// Using Semaphores and Threads in C++

#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

const int N = 5; // Buffer size

vector<int> buffer(N);
int in = 0;
int out = 0;

// Semaphores
counting_semaphore<N> empty(N); // initially all slots empty
counting_semaphore<N> full(0);  // initially no items

mutex mtx;

// Producer Function
void producer() {
    for (int item = 1; item <= 10; item++) {

        empty.acquire(); // wait if buffer full

        mtx.lock();

        buffer[in] = item;
        cout << "Produced: " << item
             << " at position " << in << endl;

        in = (in + 1) % N;

        mtx.unlock();

        full.release(); // signal item available

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

// Consumer Function
void consumer() {
    for (int i = 1; i <= 10; i++) {

        full.acquire(); // wait if buffer empty

        mtx.lock();

        int item = buffer[out];

        cout << "Consumed: " << item
             << " from position " << out << endl;

        out = (out + 1) % N;

        mtx.unlock();

        empty.release(); // signal empty slot available

        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main() {

    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();

    return 0;
}