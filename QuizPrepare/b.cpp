// Another one easy BST problem - PROBLEM B

#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define qFor(i, x, n) for(int i = x; i < n; ++i)
#define read(x) cin >> x
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i, j) cout << i << " " << j << endl
#define vt vector
#define ll long long
const int MAXN = 1e9;
 
struct node
{
    int value;
    node * left, * right;
    node(int value) {
        this-> value = value;
        left = NULL;
        right = NULL;
    }
};
node * insert (node * current, int value) {
    if (current == NULL) {
        node * new_node = new node(value);
        return new_node;
    } 
    if (value <= current->value) {
        current->left = insert(current->left, value);
    } else {
        current->right = insert(current->right, value);
    }
}

node * get_min(node * current) {
    if (current->left && current) {
        return get_min(current->left);
    }
    return current;
}

node * deletion(node * root, int value) {
    if (root == NULL) return root;
    if (value < root->value) {
        root->left = deletion(root->left, value);
    } else if (value > root->value) {
        root->right = deletion(root->right, value);
    } else {
        if (root->left == NULL) {
            node * temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node * temp = root->left;
            free(root);
            return temp;
        }
        node * temp = get_min(root->right);
        root->value = temp->value;
        root->right = deletion(root->right, temp->value);
    }
    return root;
}


void count(node * current, int value, int & counts) {
    if (current == NULL) {
        return;
    }
    if (current->value > value) {
        count(current->left, value, counts);
    } else if (current->value < value) {
        count(current->right, value, counts);
    } else {
        counts++;
        count(current->left, value, counts);
    }
}


void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    node * root = NULL;
    int n;
    cin >> n;
    For(i, n) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "insert") {
            root = insert(root, x);
        } else if (op == "delete") {
            root = deletion(root, x);
        } else {
            int counter = 0;
            count(root, x, counter);
            see(counter);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}