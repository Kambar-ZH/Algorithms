#include <iostream>
using namespace std;

struct queue
{
    int head;
    int tail;
    int a[1001];

    void push(int x)
    {
        a[tail] = x;
        cout << a[tail] << endl;
        tail++;
    }
    int pop()
    {
        if (tail != head)
        {
            head++;
            return a[head - 1];
        }
        else
        {
            return 0;
        }
    }
    string is_empty()
    {
        if (tail == head)
        {
            return "TRUE";
        }
        return "FALSE";
    } 
};

int main()
{
    struct queue q;
    q.head = 0;
    q.tail = 0;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << " ";
    cout << q.pop() << " ";
    cout << q.pop() << " ";
    cout << q.is_empty() << " ";
    return 0;
}