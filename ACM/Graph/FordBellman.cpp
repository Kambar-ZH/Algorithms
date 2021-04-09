#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int a, b, cost;
};

int n, t, v;
vector<edge> e;
const int INF = 1000000000;

void solve()
{
	vector<int> d(n, INF);
	d[v] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n * n; ++j)
			if (d[e[j].a] < INF)
				d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
}

void solve_modify() {
	vector<int> d (n, INF);
	d[v] = 0;
	for (;;) {
		bool any = false;
		for (int j=0; j<n * n; ++j)
			if (d[e[j].a] < INF)
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = d[e[j].a] + e[j].cost;
					any = true;
				}
		if (!any)  break;
	}
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
}

void solve_restore() {
	vector<int> d (n, INF);
	d[v] = 0;
	vector<int> p (n, -1);
	for (;;) {
		bool any = false;
		for (int j=0; j<n * n; ++j)
			if (d[e[j].a] < INF)
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = d[e[j].a] + e[j].cost;
					p[e[j].b] = e[j].a;
					any = true;
				}
		if (!any)  break;
	}
 
	if (d[t] == INF)
		cout << "No path from " << v << " to " << t << ".";
	else {
		vector<int> path;
		for (int cur=t; cur!=-1; cur=p[cur])
			path.push_back (cur);
		reverse (path.begin(), path.end());
 
		cout << "Path from " << v << " to " << t << ": ";
		for (size_t i=0; i<path.size(); ++i)
			cout << path[i] << ' ';
	}
}


void solve_negative_c()
{
	vector<int> d (n);
	vector<int> p (n, -1);
	int x;
	for (int i=0; i<n; ++i) {
		x = -1;
		for (int j=0; j< n * n; ++j)
			if (d[e[j].b] > d[e[j].a] + e[j].cost) {
				d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
				p[e[j].b] = e[j].a;
				x = e[j].b;
			}
	}
 
	if (x == -1)
		cout << "NO";
	else {
		int y = x;
		for (int i=0; i<n; ++i)
			y = p[y];
 
		vector<int> path;
		for (int cur=y; ; cur=p[cur]) {
			path.push_back (cur);
			if (cur == y && path.size() > 1)  break;
		}
		reverse (path.begin(), path.end());
 
		cout << "YES" << endl << path.size() << endl;
		for (size_t i=0; i<path.size(); ++i)
			cout << path[i] + 1 << ' ';
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int dist;
			scanf("%d", &dist);
			edge x; x.a = i; x.b = j; x.cost = dist;
			e.push_back(x);
		}
	}
	solve_negative_c();
	return 0;
}