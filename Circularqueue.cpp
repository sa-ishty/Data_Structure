#include <iostream>
using namespace std;

int *arr;
int front = -1;
int rear = -1;
int maxSize;

bool isEmpty() {
    return front == -1 && rear == -1;
}

bool isFull() {
    return (rear + 1) % maxSize == front;
}

void enqueue(int val) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % maxSize;
    }
    arr[rear] = val;
}
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    if (front <= rear) {
        while (i <= rear) {
            cout << arr[i] << " ";
            i++;
        }
    } else {
        while (i < maxSize) {
            cout << arr[i] << " ";
            i++;
        }
        i = 0;
        while (i <= rear) {
            cout << arr[i] << " ";
            i++;
        }
    }
    cout << endl;
}
int main() {
    int queueSize = 5;
    maxSize = queueSize;
    arr = new int[queueSize];

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(6);
    enqueue(7);

    display();

    delete[] arr;
    return 0;
}
