#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i, j) cout << i << " " << j << endl
#define vt vector
#define itn int
const int MAXN = 1e9;
 
void count_sort(vector<int> & order, vector<int> & classification) {
	int n = order.size();
	vector<int> counter(n);
	For (i, n) {
		counter[classification[i]]++;
	}
	vector<int> order_new(n), position(n);
	position[0] = 0;
	for (int i = 1; i < n; ++i) {
		position[i] = position[i - 1] + counter[i - 1];
	}
	For(i, n) {
		int j = classification[order[i]];
		order_new[position[j]] = order[i];
		position[j]++;
	}
	order = order_new;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	str += "$";
	int n = str.size();
	vector<int> order(n), classification(n);
	{
		vector<pair<char, int> > a(n);
		For(i, n) a[i] = {str[i], i};
		sort(a.begin(), a.end());
		For(i, n) order[i] = a[i].second;
		classification[order[0]] = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i].first == a[i - 1].first) {
				classification[order[i]] = classification[order[i - 1]];
			} else {
				classification[order[i]] = classification[order[i - 1]] + 1;
			}
		}
	}	
	int k = 0;
	while ((1 << k) < n) {
		For (i, n) {
			order[i] = (order[i] - (1 << k) + n) % n;
		}
		count_sort(order, classification);
		vector<int> classification_new(n);
		classification_new[order[0]] = 0;
		for (int i = 1; i < n; ++i) {
			pair<int, int> previous = {classification[order[i - 1]], classification[(order[i - 1] + (1 << k)) % n]}, 
			new_one = {classification[order[i]], classification[(order[i] + (1 << k)) % n]};
			if (new_one == previous) {
				classification_new[order[i]] = classification_new[order[i - 1]];
			} else {
				classification_new[order[i]] = classification_new[order[i - 1]] + 1;
			}
		}
		classification = classification_new;
		k++;
	}
	For(i, n) {
		look(order[i]);
	}
	return 0;
}