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
 
struct node
{
    node* next, *prev;
    int val;
    node (int val) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

struct linkedlist {
    node* head, *tail;
    linkedlist() {
        head = nullptr;
        tail = nullptr;
    }
    void push_front(int val) {
        node* newnode = new node(val);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            node* tmp = head;
            head = newnode;
            head->next = tmp;
            tmp->prev = head;
        }
    }
    void push_back(int val) {
        node* newnode = new node(val);
        if (tail == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            node* tmp = tail;
            tail = newnode;
            tmp->next = tail;
            tail->prev = tmp;
        }
    }
    void pop_front() {
        if (head->next) {
            node* todelete = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete(todelete);
        } else if (head) {
            node* todelete = head;
            delete (todelete);
            head = nullptr;
            tail = nullptr;
        }
    }
    void pop_back() {
        if (tail->prev) {
            node* todelete = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            delete(todelete);
        } else if (tail) {
            node* todelete = tail;
            delete (todelete);
            head = nullptr;
            tail = nullptr;
        }
    }
    void front() {
        if (head) {
            cout << head->val << "$" << endl;
        }
    }
    void back() {
        if (tail) {
            cout << tail->val << "$" << endl;
        }
    }
};


void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int q;
    cin >> q;
    linkedlist kama;
    For(qq, q) {
        int c;
        cin >> c;
        if (c == 1) {
            int v;
            cin >> v;
            kama.push_back(v);
        } else if (c == 2) {
            int v;
            cin >> v;
            kama.push_front(v);
        } else if (c == 3) {
            kama.pop_back();
        } else if (c == 4) {
            kama.pop_front();
        } else if (c == 5) {
            kama.front();
        } else {
            kama.back();
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}