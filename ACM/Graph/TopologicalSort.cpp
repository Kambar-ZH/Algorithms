#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100;
int n, m;
bool used[MAXN];
vector<int> graph[MAXN], ans;

void dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int to = graph[v][i];
        if (!used[to])
            dfs(to);
    }
    ans.push_back(v);
}

void top_sort()
{
    for (int i = 0; i < n; ++i)
    {
        used[i] = false;
    }
    ans.clear();
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
            dfs(i);
    }
    // while (!ans.empty()) {
    //     cout << ans.back() << " ";
    //     ans.pop_back();
    // }
    reverse(ans.begin(), ans.end());
}

int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < m; ++i)
        {
            int t, k;
            cin >> t >> k;
            --t, --k;
            graph[t].push_back(k);
        }
        top_sort();
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << " ";
    }
    return 0;
}