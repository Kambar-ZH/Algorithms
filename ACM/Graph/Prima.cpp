#include <bits/stdc++.h>
using namespace std;

int main()
{
    // входные данные
    int n;
    const int INF = 1000000000; // значение "бесконечность"
    vector< vector<int> > graph(n, vector<int>(n));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    // алгоритм
    vector<bool> visited(n);
    vector<int> minimal_edge(n, INF), sel_e(n, -1);
    minimal_edge[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!visited[j] && (v == -1 || minimal_edge[j] < minimal_edge[v]))
                v = j;
        if (minimal_edge[v] == INF)
        {
            cout << "No MST!";
            exit(0);
        }

        visited[v] = true;
        if (sel_e[v] != -1)
            cout << v << " <---> " << sel_e[v] << endl;

        for (int to = 0; to < n; ++to)
            if (graph[v][to] < minimal_edge[to])
            {
                minimal_edge[to] = graph[v][to]; // minimal_edge[3] = 3
                sel_e[to] = v;        // sel_e[3] =
            }
    }
}

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    const int INF = 1000000000; // значение "бесконечность"
    vector< vector<int> > graph(n, vector<int>(n));
    vector <int> selected_edge(n, -1), minimal_edge(n, INF), used(n, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && (v == -1 || minimal_edge[v] < minimal_edge[j]))
                v = j;
        }
        if (minimal_edge[v] == INF)
        {
            cout << "NO OST";
            break;
        }
        used[v] = true;
        if (selected_edge[v] != -1)
            cout << selected_edge[v] << " <---> " << v << endl; 
        for (int to = 0; to < n; to++)
        {
            if (minimal_edge[v] > graph[v][to])
            {
                minimal_edge[v] = graph[v][to];
                selected_edge[to] = v;
            }
        }
        
        
    }
    return 0;
}