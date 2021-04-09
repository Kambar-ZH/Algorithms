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
#define itn int
const int MAXN = 1e9;
 
struct node {
	int value;
	node * left, * right;
	node (int value, node * left, node * right) {
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

struct tree {
	node * root;
	tree () {
		root = NULL;
	}
	void append(int value) {
		node * new_node = new node(value, NULL, NULL);
		if (root == NULL) {
			root = new_node;
		} else {
			node * current = root;
			while (true) {
				if (new_node->value > current->value) {
					if (current->right == NULL) {
						current->right = new_node;
						break;
					} else {
						current = current->right;
					}
				} else if (new_node->value < current->value) {
					if (current->left == NULL) {
						current->left = new_node;
						break;
					} else {
						current = current->left;
					}
				} else {
					delete new_node;
					break;
				}
			}
		}
	}
	int get_depth(node * current, vector<int> & a) {
        if (current == NULL) return 0;
        int left_son = get_depth(current->left, a) + 1;
        int right_son = get_depth(current->right, a) + 1;
        a.push_back(min(left_son - 1, right_son - 1));
        return max(left_son, right_son);
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tree bt;
	int n;
    cin >> n;
    For(i, n) {
        int x;
        cin >> x;
        bt.append(x);
    }
    vector<int> a;
    bt.get_depth(bt.root, a);
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
	return 0;
}