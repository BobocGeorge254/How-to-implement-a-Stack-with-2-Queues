#include <iostream>
#include <queue>

using namespace std;

/*
class Queue {
    int *q;
    int head , tail ;
public :
    Queue() {
        head = tail = -1 ;
        q = new int[256];
    }
    ~Queue() {
        delete []q;
    }
    void push(int x) {
        if (head == tail && head == -1) {
            head = tail = 0 ;
            q[head] = x ;
        }
        else {
            head ++ ;
            q[head] = x ;
        }
    }
    bool empty(){
        if ( head == tail && head == -1 )
            return 1 ;
        return head == tail - 1;
    }
    void pop() {
        tail ++ ;
        while ( tail > 0 ) {
            for ( int c_head = head ; c_head >= tail ; c_head -- )
                q[c_head + 1] = q[c_head] ;
            tail -- ;
        }
    }
    int front(){
        return q[tail] ;
    }
    void operator&= (Queue);

};

void Queue::operator&= (Queue q2) {

    while (!(this->empty())) {
        int x = this->front();
        this->pop();
        q2.push(x) ;
    }
}
*/

class Stack {
    queue<int> q1;
public :
    void push(int x) {
        queue<int> q2;
        q2.push(x) ;
        while (!q1.empty()) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1 = q2 ;
    }
    void pop() {
        q1.pop();
    }
    int top(){
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(10);
    cout << s.top();
    s.pop();
    cout << s.top();
    s.pop();
    cout << s.top() << " " << s.empty();
}
