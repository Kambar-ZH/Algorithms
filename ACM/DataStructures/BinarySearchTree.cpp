#include <bits/stdc++.h>
using namespace std;
 

template <typename T>
struct Set
{
    Set();
    ~Set();
    int get_size();
    int get_depth();
    int count(int data);
    void insert(int data);
    int cmp(int data, int current_data);
    template <typename T1>
    struct Node
    {
        Node *pLeft, *pRight;
        int data;
        Node (int data, Node *pLeft = NULL, Node *pRight = NULL)
        {
            this->data = data;
            this->pLeft = pLeft;
            this->pRight = pRight;
        }
    };
    int size;
    int depth;
    Node<int>* root;
    void print_sorted(Node<T> *root);
};

template <typename T>
Set<T>::Set()
{
    size = 0;
    depth = 0;
    root = NULL;
}

template <typename T>
Set<T>::~Set()
{

}

template <typename T>
int Set<T>::cmp(int data, int current_data)
{
    if (data > current_data) return 1; 
    else if (data < current_data) return -1;
    return 0;
}

template <typename T>
int Set<T>::count(int data)
{
    Node<int> *current = root;
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
void Set<T>::print_sorted(Node<T> *root)
{
    if (root != NULL) {
        print_sorted(root->pLeft);
        cout << root->data << endl;
        print_sorted(root->pRight);
    }
}

// template <typename T>
// void Set<T>::leaves() 
// {
//     while
// }

template <typename T>
int Set<T>::get_size()
{
    return size;
}

template <typename T>
int Set<T>::get_depth()
{
    return depth;
}

template <typename T>
void Set<T>::insert(int data)
{
    if (root == NULL) {
        root = new Node<int>(data);
        depth += 1;
    }
    else {
        Node<int> *current = this->root;
        Node<int> *previous = current;
        int choose, current_depth(1);
        while (current != NULL) {
            current_depth += 1;
            if (cmp(data, current->data) == 1) {
                choose = 1;
                previous = current;
                current = current->pRight;
            } else if (cmp(data, current->data) == -1) {
                choose = 0;
                previous = current;
                current = current->pLeft;
            } else {
                return;
            }
        }
        if (current_depth > depth) {
            depth = current_depth;
        } if (choose) {
            previous->pRight = new Node<int>(data);
        } else {
            previous->pLeft = new Node<int>(data);
        }
    }
    size += 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    Set<int> set_;
    int elem;
    while(true) {
        cin >> elem;
        if (elem == 0) break;
        set_.insert(elem);
        cin.ignore();
    }
    set_.print_sorted(set_.root);
    return 0;
}   