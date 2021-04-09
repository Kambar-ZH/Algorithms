#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
class List
{
public:
    List(/* args */); // constructor
    ~List(); // distructor

    void push_back(T data); // methods
    void pop_front();
    void clear();
    int GetSize() { return Size; }
    T& operator[](const int index); // operator overload

    void push_front(T data);
    void insert(T value, int index);
    void remove_at(int index);
    void pop_back();

private:
    template <typename T1> // template for class Node
    class Node
    {
    public:
        Node *pNext; // pointer for next element
        T1 data; // template for data
        Node(T1 data = T1(), Node *pNext = NULL)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size; // save the size
    Node<T> *head; // head is the pointer for begin
};

template<typename T>
List<T>::List() // constructor
{
    Size = 0;
    head = NULL;
}

template<typename T>
List<T>::~List() // distructor
{
    cout << "Distructor called" << endl;
    clear();
}

template<typename T>
void List<T>::clear() // while size != 0 we pop the elements
{
    while(Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) // head looks for new value
{   
    head = new Node<T>(data, head);
    Size++; // increase size
}

template<typename T>
void List<T>::pop_front()
{   
    Node<T> *temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == NULL)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != NULL)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template <typename T>
void List<T>::insert(T value, int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        Node<T> *previous = this->head;

        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }

        Node<T> *newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }
}

template <typename T>
void List<T>::remove_at(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
    }      
}

template <typename T>
void List<T>::pop_back()
{
    remove_at(Size - 1);
}

template <typename T>
T & List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while (current!=NULL)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

int main()
{
    List<int> lst;
    int numbersCount;
    cin >> numbersCount;

    for (int i = 0; i < numbersCount; ++i)
    {
        lst.push_back(rand() % 10);
    }
    for (int i = 0; i < lst.GetSize(); ++i)
    {
        cout << lst[i] << " ";
    }

    lst.pop_front();
    cout << endl << "Pop front" << endl;
    for (int i = 0; i < lst.GetSize(); ++i)
    {
        cout << lst[i] << " ";
    }

    lst.push_front(3);
    cout << endl << "Push front 3" << endl;
    for (int i = 0; i < lst.GetSize(); ++i)
    {
        cout << lst[i] << " ";
    }

    lst.insert(999, 1);
    cout << endl << "Insert 999 on index 1" << endl;
    for (int i = 0; i < lst.GetSize(); ++i)
    {
        cout << lst[i] << " ";
    }

    lst.remove_at(1);
    cout << endl << "Remove 999 at index 1" << endl;
    for (int i = 0; i < lst.GetSize(); ++i)
    {
        cout << lst[i] << " ";
    }

    lst.pop_back();
    cout << endl << "Pop back" << endl;
    for (int i = 0; i < lst.GetSize(); ++i)
    {
        cout << lst[i] << " ";
    }

    lst.clear();
    cout << endl << "Clear" << endl;
    for (int i = 0; i < lst.GetSize(); ++i)
    {
        cout << lst[i] << " ";
    }

    return 0;
}