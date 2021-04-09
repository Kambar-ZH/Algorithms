#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e9;

struct node {
    int left, right;
    int maximum, add;
    node * ch_left, * ch_right;
};

node * build(int left, int right, vector<int> & a) {
    if (left > right) {
        return NULL;
    }
    node * res = new node;
    res->left = left;
    res->right = right;
    if (left == right) {
        res->ch_left = NULL;
        res->ch_right = NULL;
        res->maximum = a[left];
        res->add = 0;
    } else {
        int mid = (left + right) / 2;
        res->ch_left = build(left, mid, a);
        res->ch_right = build(mid + 1, right, a);
        res->maximum = max(res->ch_left->maximum, res->ch_right->maximum);
    }
    return res;
}

int query(int left, int right, node * root) {
    if (right < root->left || left > root->right) {
        return -MAXN;
    }
    if (root->left >= left && root->right <= right) {
        return root->maximum + root->add;
    }
    return max(query(left, right, root->ch_left), query(left, right, root->ch_right)) + root->add;
}

int query_slow(int left, int right, vector<int> & a) {
    if (left > right) {
        return -MAXN;
    }
    int res = a[left];
    for (int i = left + 1; i <= right; i++) {
        res = max(res, a[i]);
    }
    return res;
}

void update(node * root, int index, int value) {
    if (index < root->left || index > root->right) {
        return;
    }
    if (root->left == root->right) {
        root->maximum = value;
        return;
    }
    update(root->ch_left, index, value);
    update(root->ch_right, index, value);
    root->maximum = max(root->ch_left->maximum, root->ch_right->maximum);
}

void update(node * root, int left, int right, int delta) {
    if (right < root->left || left > root->right) {
        return;
    }
    if (root->left >= left && root->right <= right) {
        root->add += delta;
        return;
    }
    update(root->ch_left, left, right, delta);
    update(root->ch_right, left, right, delta);
    root->maximum = max(root->ch_left->maximum + root->ch_left->add, root->ch_right->maximum + root->ch_right->add);
}

void update_slow(vector<int> & a, int left, int right, int delta) {
    for (int i = left; i <= right; i++) {
        a[i] += delta;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    vector<int> a;
    int n = 100;
    for (int i = 0; i < n; i++) {
        a.push_back(rand() % 100);
    }
    node * root = build(0, n - 1, a);
    for (int ll = 0; ll < n; ll++)
    {
        for (int rr = 0; rr < n; rr++)
        {    
            int delta = rand() % 100;
            update(root, ll, rr,  delta);
            update_slow(a, ll, rr,  delta);
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (query(i, j, root) != query_slow(i, j, a)) {
                        cout << "FAIL";
                        return 0;
                    }
                }
            }
        }
        
    }
    
    cout << "OK";
    return 0;
}
10 5
2 0 9
1 0 9 10
2 0 9
2 0 8