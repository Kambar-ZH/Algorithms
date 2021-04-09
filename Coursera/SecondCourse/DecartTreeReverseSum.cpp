#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
struct dec_car{
    template <typename T1>
    struct Node {
        int value, priority, count, summa;
        bool reversed;
        Node<T> * left, * right;
        Node(int value, int priority, bool reversed = false, int count = 1, Node<T> * left = NULL, Node<T> * right = NULL) {
            this->value = value;
            this->priority = priority;
            this->reversed = reversed;
            this->summa = value;
            this->count = count;
            this->left = left;
            this->right = right;
        }
    };
    Node<T> * root = NULL;

    Node<T> * merge(Node<T> * pleft, Node<T> * pright) {
        if (pleft == NULL || pright == NULL) {
            return pleft ? pleft : pright;
        } if (pleft->priority <= pright->priority) {
            pleft->right = merge(pleft->right, pright);
            recalc(pleft);
            return pleft;
        } else {
            pright->left = merge(pleft, pright->left);
            recalc(pright);
            return pright;
        }
    }

    pair<Node<T> *, Node<T> *> split(Node<T> * root, int key) {
        if (root == NULL) {
            return {NULL, NULL};
        }
        int l = (root->left) ? root->left->count : 0;
        if (l < key) {
            auto res = split(root->right, key - l - 1);
            root->right = res.first;
            recalc(root);
            return {root, res.second};
        } else {
            auto res = split(root->left, key);
            root->left = res.second;
            recalc(root);
            return {res.first, root};
        }
    }

    Node<T> * insert(Node<T> *root, int key, int priority, int index) {
        auto res = split(root, index);
        Node<T> * new_node = new Node<T>(key, priority);
        return merge(merge(res.first, new_node), res.second); 
    }

    void get_sum(Node<T> *root, int key, int key2) {
        auto res = split(root, key2);
        auto res2 = split(res.first, key - 1);
        int summa = (res2.second) ? res2.second->summa : -1;
        root = merge(merge(res2.first, res2.second), res.second);
        cout << summa << endl;
    }

    void reverse(Node<T> *root, int key, int key2) {
        auto res = split(root, key2);
        auto res2 = split(res.first, key - 1);
        res2.second->reversed ^= true;
        root = merge(merge(res2.first, res2.second), res.second);
    }

    void print(Node<T> * root) {
        if (root != NULL) {
            print(root->left);
            cout << root->value <<  " " << root->summa << endl;
            print(root->right);
        }
    }

    void recalc(Node<T> * noda) {
        int res = (noda->right) ? noda->right->count : 0;
        int res2 = (noda->left) ? noda->left->count : 0;
        noda->count = res + res2 + 1;
        int sum2 = (noda->right) ? noda->right->summa : 0;
        int sum1 = (noda->left) ? noda->left->summa : 0;
        noda->summa =  sum1 + sum2 + noda->value;
        if (!noda->left || !noda->right) {
            noda->reversed = false;
        } else if (noda->reversed) {
            swap(noda->left, noda->right);
            noda->reversed = false;
            noda->left->reversed ^= true;
            noda->right->reversed ^= true;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    dec_car<int> tree;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        tree.root = tree.insert(tree.root, value, rand(), i);
    }
    for (int i = 0; i < m; i++) {
        int op, start, end;
        cin >> op >> start >> end;
        if (op == 1) {
            tree.reverse(tree.root, start, end);
        } else {
            tree.get_sum(tree.root, start, end);
        }
    }
    return 0;
}