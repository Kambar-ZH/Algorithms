#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define pb push_back
#define ends " "
#define For(i,n) for(int i=0;i<n;i++)
#define FoR(i,n,x) for(int i=x;i<n;i++)
template<typename T>
void enter(vector<T>& a, int n){
    For(i,n) cin >> a[i];
}
template<typename T>
void print(vector<T>& a){
    For(i,a.size()) cout<<a[i]<<ends;
    cout << endl;
}

vector<int> prefix_function (vector<int> & s) {
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] > s[j])
			j = pi[j-1];
		if (s[i] <= s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n), p;
    For(i,n) cin >> a[i];
    // reverse(a.begin(), a.end());
    p = prefix_function(a);
    reverse(p.begin(), p.end());
    For(i, n) cout << p[i] << " ";
    // int q;
    // cin >> q;
    // For(i, q) {
    //     int l, r;
    //     cin >> l >> r;
    //     cout << p[r] << endl;
    // }
    return 0;
}