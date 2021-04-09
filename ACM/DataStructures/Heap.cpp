#include <bits/stdc++.h>
using namespace std;
 
struct heap
{
    vector<int> tree;
    heap() {
        tree.push_back(0);
    }

    void push (int x) {
        tree.push_back(x);
        shift_up(tree.size() - 1);
    }

    void shift_up (int v) {
        if (v == 1)
            return;
        if (tree[v / 2] < tree[v]) {
            swap(tree[v / 2], tree[v]);
            shift_up (v / 2);
        }
    }

    void pop ()
    {
        if (tree.size() > 1) {
            tree[1] = tree.back();
            tree.pop_back();
            shift_down(1);
        }
    }

    void shift_down (int v)
    {
        if (v * 2 >= tree.size())
            return;
        int max_ind;
        if (v * 2 + 1 == tree.size())
            max_ind = 2 * v;
        else if (tree[2 * v] >= tree[2 * v + 1])
            max_ind = 2 * v;
        else
            max_ind = 2 * v + 1;
        
        if (tree[v] < tree[max_ind]) {
            swap(tree[v], tree[max_ind]);
            shift_down(max_ind);
        }
    }

    bool empty () {
        return tree.size() == 1;
    }

    int max () {
        if (tree.size() > 1)
            return tree[1];
    }

};


int main()
{
    heap myheap;
    myheap.push(10);
    myheap.push(19);
    myheap.push(13);
    myheap.push(7);
    myheap.push(18);
    cout << myheap.max() << endl;
    myheap.pop();
    cout << myheap.max() << endl;
    myheap.pop();
    cout << myheap.max() << endl;
    myheap.pop();
    cout << myheap.max() << endl;
    myheap.pop();
    cout << myheap.max() << endl;
    return 0;
}