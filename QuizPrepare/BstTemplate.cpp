// Problem A. Triangle Binary Search Tree
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

node * find(node * current, int value) {
    if (current == NULL) return NULL;
    if (current->value > value) {
        return find(current->left, value);
    } else if (current->value < value) {
        return find(current->right, value);
    }
    return current;
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

int get_depth(node * current, vector<int> & a) {
    if (current == NULL) return 0;
    int left_son = get_depth(current->left, a) + 1;
    int right_son = get_depth(current->right, a) + 1;
    a.push_back(min(left_son - 1, right_son - 1));
    return max(left_son, right_son);
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
        int x;
        cin >> x;
        root = insert(root, x);
    }
    vector<int> a;
    get_depth(root, a);
    int mini = MAXN;
    For(i, a.size()) {
        if (a[i] != 0 && mini > a[i]) {
            mini = a[i];
        }
    }
    int answer = 0;
    For(i, n) {
        if (a[i] >= mini) {
            answer++;
        }
    }
    cout << answer;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}