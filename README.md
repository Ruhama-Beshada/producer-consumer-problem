# Producer-Consumer Problem in C++

A clean, modern C++ implementation of the classic Producer-Consumer synchronization problem using threads and semaphores. This project demonstrates how to coordinate concurrent tasks sharing a bounded buffer to prevent race conditions and deadlocks.

## How It Works

The program simulates two concurrent threads interacting through a fixed-size buffer ($N = 5$):
*   **The Producer:** Generates integer data (1 through 10) and places them into the next available slot.
*   **The Consumer:** Extracts those integers from the buffer sequentially and processes them.

### Synchronization Mechanism
To guarantee thread safety, the system uses three core components:
1.  **`std::counting_semaphore` (Empty Slots):** Tracks available slots in the buffer, forcing the Producer to block if the buffer is completely full.
2.  **`std::counting_semaphore` (Full Slots):** Tracks available items ready for consumption, forcing the Consumer to block if the buffer goes empty.
3.  **`std::mutex`:** Acts as a mutual exclusion lock to guarantee that only one thread can modify the buffer indices or write to `std::cout` at any given millisecond.

---

## File Structure

*   `main.cpp` - Contains the full source code (Producer, Consumer, and main execution loops).

---

## Prerequisites & Compilation

This codebase utilizes standard library features introduced in **C++20** (specifically `<semaphore>`). Ensure your compiler is fully up to date.

### Using GCC (Linux/macOS)
Compile via terminal with the C++20 standard flag enabled:
```bash
g++ -std=c++20 main.cpp -o producer_consumer
