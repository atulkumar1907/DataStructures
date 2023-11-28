#include <iostream>
using namespace std;

#define n 100

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue();
    void enqueue(int val);
    void dequeue();
    int peek();
    bool empty();
};

queue::queue()
{
    arr = new int[n];
    front = -1;
    back = -1;
}

void queue::enqueue(int val)
{
    if (back == n - 1)
    {
        cout << "Overflow" << endl;
        return;
    }
    
    back++;
    arr[back] = val;

    if (front == -1)
    {
        front++;
    }
}

void queue::dequeue()
{

    if (back < front || front == -1)
    {
        cout << "No Element" << endl;
        return;
    }
    front++;
}

int queue::peek()
{
    if (back < front || front == -1)
    {
        cout << "No Element" << endl;
        return -1;
    }

    return arr[front];
}

bool queue::empty()
{
    if (back < front || front == -1)
    {

        return true;
    }
}

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;

    return 0;
}