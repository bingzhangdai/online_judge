#include <iostream>
#include <atomic>
#include <functional>
#include <thread>
using namespace std;

class Foo {
    atomic<int> flag = { 1 };
public:
    Foo() {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag.store(2, memory_order_release);
    }

    void second(function<void()> printSecond) {
        const auto expected = 2;
        while (flag.load(memory_order_acquire) < expected) {
            this_thread::yield();
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag.store(3, memory_order_acquire);
    }

    void third(function<void()> printThird) {
        const auto expected = 3;
        while (flag.load(memory_order_acquire) < expected) {
            this_thread::yield();
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

// may not be right, because of reordering
class Foo_Volatile {
    volatile int flag = 1;
public:
    Foo() {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 2;
    }

    void second(function<void()> printSecond) {
        const auto expected = 2;
        while (flag < expected) {
            this_thread::yield();
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag = 3;
    }

    void third(function<void()> printThird) {
        const auto expected = 3;
        while (flag < expected) {
            this_thread::yield();
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

int main(void) {
    return 0;
}
