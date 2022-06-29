#include <iostream>
#include <stack>
#include "../test_runner/test_runner.h"

class MyQueue {
public:
    MyQueue() {
        size_ = 0;
    }

    void push(int x) {
        front_.push(x);
        if (empty() == true){
            first_ = &front_.top();
        }
        size_++;
    }

    int pop() {
        first_ = first_ + 1;
        size_ -- ;
        return *(first_ -1);
    }

    int peek() {
        return *first_;
    }

    bool empty() {
        return size_ == 0;
    }
private:
    std::stack<int> front_;
    int * first_ = new int ;
    size_t size_;
};

void SimpleTest(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    ASSERT_EQUAL(myQueue->peek(),1); // return 1
    ASSERT_EQUAL(myQueue->pop(),1); // return 1, queue is [2]
    ASSERT_EQUAL(myQueue->empty(), false);
    ASSERT_EQUAL(myQueue->pop(),2);
    ASSERT_EQUAL(myQueue->empty(), true);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
