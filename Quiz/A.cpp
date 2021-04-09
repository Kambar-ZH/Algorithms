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
    string data;
    node * pnext;
    node(string data, node * pnext) {
        this->data = data;
        this->pnext = pnext;
    }
};

struct mystack {
    int size = 0;
    node * head = NULL, * tail = NULL;

    void insert(string & value) {
        if (head == NULL) {
            node * current = new node(value, NULL);
            head = current;
            tail = current;
        } else {
            node * current = new node(value, NULL);
            tail->pnext = current;
            tail = tail->pnext;
        }
        size++;
    }

    void shift() {
        node * current = new node(head->data, NULL);
        node * todelete = head;
        head = head->pnext;
        tail->pnext = current;
        tail = tail->pnext;
        delete todelete;
    }

    void show() {
        node * current = head;
        while (current != NULL) {
            look(current->data);
            current = current->pnext;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    mystack st;
    For(i, n) {
        string word;
        cin >> word;
        st.insert(word);
    }
    For(i, k) {
        st.shift();
    }
    st.show();
    return 0;
}