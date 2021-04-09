#include <iostream>
using namespace std;
 
struct stack
{

    int a[1000];
    int head;

    void push(int x)
    {
        head++;
        a[head] = x;
        cout << a[head] << endl;
    }
    int pop()
    {
        if (head != -1)
        {
            head--;
            return a[head + 1];
        }
        else
        {
            cout << "Error" << endl;
        }
        
    }
    string is_empty()
    {
        (head == -1) ? cout << "TRUE" : cout << "FALSE";
    }
};

int main()
{
    struct stack stc;
    stc.head = -1;
    stc.push(1);
    stc.push(2);
    stc.push(3);
    cout << stc.pop() << " ";
    cout << stc.pop() << " ";
    cout << stc.pop() << " ";
    cout << stc.is_empty() << " ";
    return 0;
}