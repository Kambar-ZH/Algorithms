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
vt<int> pf(string s) {
    int n = s.length();
    vt<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}
 
void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p = pf(s);
    int length = p[n - 1];
    set<int> st;
    for(int i = 1; i < n - 1; i++) 
        st.insert(p[i]);
    while(length){
        if(st.find(length) == st.end()) length = p[length - 1];
        else{
          cout << s.substr(0, length) << endl;
          return;
        }
    }
    cout << "Just a legend" << endl;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}