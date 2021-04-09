#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct dec_car{
    template <typename T1>
    struct Node {
        int x, y, index;
        Node<T> * left;
        Node<T> * right;
        Node(int x, int y, int index, Node<T> * left = NULL, Node<T> * right = NULL) {
            this->x = x;
            this->y = y;
            this->index = index;
            this->left = left;
            this->right = right;
        }
        ~Node() {
            if (left) {
                delete left;
            }
            if (right) {
                delete right;
            }
        }
    };
    int size = 0;
    Node<T> * root = NULL;
    priority_queue<pair <pair<int, int>, pair<int, int> > , vector<pair<pair<int, int>, pair<int, int> > >, greater<pair<pair<int, int>, pair<int, int> > > >answer;
    Node<T> * merge(Node<T> * pleft, Node<T> * pright) {
        if (pleft == NULL || pright == NULL) {
            return pleft ? pleft : pright;
        } if (pleft->y <= pright->y) {
            pleft->right = merge(pleft->right, pright);
            return pleft;
        } else {
            pright->left = merge(pleft, pright->left);
            return pright;
        }
    }

    pair<Node<T> *, Node<T> *> split(Node<T> * root, int key) {
        if (root == NULL) {
            return {NULL, NULL};
        }
        if (root->x <= key) {
            auto res = split(root->right, key);
            root->right = res.first;
            return {root, res.second};
        } else {
            auto res = split(root->left, key);
            root->left = res.second;
            return {res.first, root};
        }
    }


    Node<T> * insert(Node<T> *root, int key, int priority) {
        auto res = split(root, key);
        Node<T> * new_node = new Node<T>(key, priority, size + 1);
        size++;
        return merge(merge(res.first, new_node), res.second); 
    }

    Node<T> * erase(Node<T> * root, int key) {
        auto res1 = split(root, key);
        auto res2 = split(res1.first, key - 1);
        delete res2.second;
        return merge(res2.first, res1.second);
    }

    void print(Node<T> * root, int pre = 0) {
        if (root != NULL) {
            print(root->right, root->index);
            print(root->left, root->index);
            answer.push({{root->index, pre}, {(root->left) ? root->left->index : 0, (root->right) ? root->right->index : 0}});
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    dec_car<int> tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree.root = tree.insert(tree.root, x, y);
    }
    cout << "YES" << endl;
    tree.print(tree.root);
    while (!tree.answer.empty()) {
        cout << tree.answer.top().first.second << " " << tree.answer.top().second.first << " " << tree.answer.top().second.second << endl;
        tree.answer.pop();
    }
    return 0;
}