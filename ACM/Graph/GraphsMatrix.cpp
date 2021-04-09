#include <bits/stdc++.h>
using namespace std;
 
bool graph[1000][1000];

int main()
{
    int n, m;
    cin >> n>> m;

    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        u--, v--;

        graph[u][v] = graph[v][u] = true;
    }
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                c++;
            }
        }
        cout << c << " edges adjacent to vertex " << i + 1 << endl;
    }    
    
    return 0;
}