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

int left_most(vector<int>& a, int x){
    int left = -1, right = a.size();
    while(left + 1 < right){
        int m = (left + right) / 2;
        if(a[m] > x) right = m;
        else left = m;
    }
    return left;
}
int right_most(vector<int> & a, int x){
    int left = -1, right = a.size();
    while(left + 1 < right){
        int m = (left + right) / 2;
        if(a[m] >= x) right = m;    
        else left = m;
    }
    return right;
}

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    For(i, n) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 0; i < k; i ++){    
        int left ,right, left_s, right_s ;
        cin >> left>> right>>left_s>> right_s;
        if(min(right, right_s)>=max(left,left_s))
            cout << left_most(a,max(right, right_s)) - right_most(a,min(left,left_s)) + 1<< endl;
        else 
            cout << left_most(a,right) - right_most(a,left) + 1 + (left_most(a, right_s) - right_most(a,left_s) + 1)<< endl;
    }
    return 0;
}