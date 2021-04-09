#include <bits/stdc++.h>
using namespace std;
 
vector<int> graph[100000];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        int c = 0;
        for (int v = 0; v < graph[i].size(); ++v)
        {
            c++;
        }
        cout << c << " edjes adjacent to vertex " << i + 1 << endl;
    }
    return 0;
}