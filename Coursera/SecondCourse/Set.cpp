#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
struct Set
{
    Set();
    ~Set();
    void pop();
    void clear();
    int count(string data);
    void insert(string data);
    int cmp(string data, string current_data);
    template <typename T1>
    struct Node
    {
        Node *pLeft, *pRight;
        string data;
        Node (string data, Node *pLeft = NULL, Node *pRight = NULL)
        {
            this->data = data;
            this->pLeft = pLeft;
            this->pRight = pRight;
        }
    };
    int Size;
    Node<string>* root;
};

template <typename T>
Set<T>::Set()
{
    Size = 0;
    root = NULL;
}

template <typename T>
Set<T>::~Set()
{
    // clear();
    // cout << root->data;
}

template <typename T>
int Set<T>::cmp(string data, string current_data)
{
    for (int i = 0; i < current_data.length(); i++)
    {
        if (data[i] > current_data[i]) return 1; 
        else if (data[i] < current_data[i]) return -1;
    }
    return 0;
}

template <typename T>
int Set<T>::count(string data)
{
    Node<string> *current = root;
    while (true)
    {
        if (current == NULL)
            return 0;
        if (cmp(data, current->data) == 0) {
            return 1;
        } else if (cmp(data, current->data) == 1) {
            current = current->pRight;
        } else {
            current = current->pLeft;
        }
    }
}

template <typename T>
void Set<T>::insert(string data)
{
    if (root == NULL) {
        root = new Node<string>(data);
    }
    else {
        Node<string> *current = this->root;
        while (true) {
            if (current->pLeft == NULL && current->pRight == NULL) break;
            if (cmp(data, current->data) == 1) {
                current = current->pRight;
            } else if (cmp(data, current->data) == -1) {
                current = current->pLeft;
            } else {
                return;
            }
        }
        if (cmp(data, current->data) == 1)
            current->pRight = new Node<string>(data);
        else if (cmp(data, current->data) == -1) {
            current->pLeft = new Node<string>(data);
        } else {
            return;
        }
        // if(root->pLeft != NULL)
        // cout << root->pLeft->data << endl;
        // if(root->pRight != NULL)
        // cout << root->pRight->data << endl;
        // cout << "Ok "
    }
    Size += 1;
}

template <typename T>
void Set<T>::pop()
{
    if (Size <= 1)
        return;
    else {
        Node<string> *current = this->root;
        while (true) {
            if (current->pLeft != NULL) {
                current = current->pLeft;
            } else if (current->pRight != NULL) {
                current = current->pRight;
            } else {
                break;
            }
        }
        cout << current->data << endl; 
        delete current;
        Size--;
    }
}

template <typename T>
void Set<T>::clear()
{
    while (Size != 1)
    {
        pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    string b, a;
    cin >> b >> a;
    Set<string> shifts;
    int count = 0;
    for (int shift = 0; shift < a.length(); shift++)
    {
        shifts.insert(a.substr(shift) + a.substr(0, shift));
        // cout << a.substr(shift) + a.substr(0, shift) << endl;
    }
    for (int i = 0; i < b.length() - a.length() + 1; i++)
    {
        string shiftB = b.substr(i, a.length());
        if (shifts.count(shiftB)) count += 1;
    }
    // cout << shifts.root->pRight->data;
    cout << count;
    // shifts.pop();
    // shifts.pop();
    // cout << shifts.Size;
    return 0;
}   