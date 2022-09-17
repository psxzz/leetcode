#include <bits/stdc++.h>

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
   public:
    MyQueue() {}

    void push(int x) {
        while (!head.empty()) {
            tail.push(head.top());
            head.pop();
        }

        head.push(x);

        while (!tail.empty()) {
            head.push(tail.top());
            tail.pop();
        }
    }

    int pop() {
        int tmp = head.top();
        head.pop();
        return tmp;
    }

    int peek() { return head.top(); }

    bool empty() { return head.empty(); }

   private:
    std::stack<int> head;
    std::stack<int> tail;
};

int main() {
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    assert(1 == obj->peek());
    assert(1 == obj->pop());
    assert(false == obj->empty());

    delete obj;
    return 0;
}