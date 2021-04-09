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
 
struct node
{
    int data;
    node * pnext, * previous;
    node(int data, node * pnext, node * previous) {
        this->data = data;
        this->pnext = pnext;
        this->previous = previous;
    }
};

struct mystack {
    int size = 0;
    node * head = NULL, * tail = NULL;
    int num_of_reverse = 0;

    void insert(int & value) {
        if (num_of_reverse % 2 == 0) {
            if (head == NULL) {
                node * current = new node(value, NULL, NULL);
                head = current;
                tail = current;
            } else {
                node * current = new node(value, NULL, tail);
                tail->pnext = current;
                tail = tail->pnext;
            }
        } else {
            if (tail == NULL) {
                node * current = new node(value, NULL, NULL);
                head = current;
                tail = current;
            } else {
                node * current = new node(value, head, NULL);
                head->previous = current;
                head = head->previous;
            }
        }
        size++;
    }

    void reverse() {
        num_of_reverse++;
    }

    void show() {
        if (num_of_reverse % 2 == 0) {
            node * current = head;
            while (current != NULL) {
                look(current->data);
                current = current->pnext;
            }
        } else {
            node * current = tail;
            while (current != NULL) {
                look(current->data);
                current = current->previous;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    mystack st;
    For(i, n) {
        int x;
        cin >> x;
        if (x == 1) {
            int y;
            cin >> y;
            st.insert(y);
        } else {
            st.reverse();
        }
    }
    st.show();
    return 0;
}