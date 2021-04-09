#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define For(i, n) for(int i = 0; i < n; ++i)
#define qFor(i, x, n) for(int i = x; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i) cout << i.first << " " << i.second << endl
#define pa pair<int, int>
#define vt vector
#define ll long long
#define ld long double
const int MAXN = 1e9;
 
template<typename T>
void read(vt<T> & a) {
    For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
    For(i, a.size()) cout << a[i] << " " ;
    cout << endl;
}

struct node {
    node* l, * r;
    int val;
    node (int val) {
        this->val = val;
        l = nullptr;
        r = nullptr;
    }
};

struct bst {
    node* root;
    bst () {
        root = nullptr;
    }
    node* insert(node* root, int val) {
        if (root == nullptr) {
            node* newNode = new node(val);
            return newNode;
        } 
        if (root->val <= val) {
            root->r = insert(root->r, val);
        } else {
            root->l = insert(root->l, val);
        }
        return root;
    }

    node* deleteNode(node* root, int key) {
        if (!root) {
            return root;
        }
        if (key < root->val) {
            root->l = deleteNode(root->l, key);
        }
        else if (key > root->val) {
            root->r = deleteNode(root->r, key);
        }
        else {
            if (!root->l && !root->r) {
                free(root);
                return nullptr;
            } else if (root->l && root->r) {
                node* min_left_node = get_min(root->r);
                root->val = min_left_node->val;
                delete(min_left_node);
                return root;
            } else if (root->l) {
                node* temp = root->l;
                delete root;
                return temp;
            } else {
                node* temp= root->r;
                delete root;
                return temp;    
            }
        }
    }

    node* get_min(node* root) {
        if (root->l && root->l != nullptr) {
            return get_min(root->l);
        }
        return root;
    }

    void inorder(node* root) {
        if (root == nullptr) return;
        inorder(root->l);
        cout << root->val << " ";
        inorder(root->r);
    }

    void leaves(node* root) {
        if (!root) return;
        if (!root->l && !root->r) {
            cout << root->val << endl;   
        }
        leaves(root->l);
        leaves(root->r);
    }
    void parents(node* root) {
        if (!root) return;
        if (root->l || root->r) {
            cout << root->val << endl;   
        }
        parents(root->l);
        parents(root->r);
    }
};  
 
void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vt<int> a(n);
    read(a);
    bst kama;
    For(i, n) {
        kama.root = kama.insert(kama.root, a[i]);
    }
    kama.parents(kama.root);
    // kama.leaves(kama.root);
    // kama.inorder(kama.root);
    // int m;
    // cin >> m;
    // For(i, m) {
    //     int c;
    //     cin >> c;
    //     if (c == 1) {
    //         int del;
    //         cin >> del;
    //         kama.root = kama.deleteNode(kama.root, del);
    //     } else {
    //         cout << kama.get_min(kama.root)->val << endl;
    //     }
    // }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}