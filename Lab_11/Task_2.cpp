#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};

class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
    T* arr;
    int front, rear, capacity, count;

public:
    Queue(int size) {
        capacity = size;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T item) {
        if (count == capacity)
            throw QueueOverflowException();

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    T dequeue() {
        if (count == 0)
            throw QueueUnderflowException();

        T item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }
};

int main() {
    Queue<int> q(3);
    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
    }
    catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to dequeue from an empty queue..." << endl;
        Queue<int> emptyQ(2);
        emptyQ.dequeue();
    }
    catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
