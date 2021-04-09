#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int width, vertix;
    cin >> width >> vertix;
    int adjacency_matrix[width][width];
    for(int i = 0; i < width; ++ i)
    {
        for (int j = 0; j < width; ++j)
        {
            cin >> adjacency_matrix[i][j];
        }
    }
    stack<int> plan;
    plan.push(--vertix);
    adjacency_matrix[vertix][vertix] = 1;
    int counter = 1;
    while (!plan.empty())
    {
        vertix = plan.top();
        plan.pop();
        for (int i = 0; i < width; ++i)
        {
            if (adjacency_matrix[vertix][i] && !adjacency_matrix[i][i])
            {
                plan.push(i);
                adjacency_matrix[i][i] = 1;
                counter += 1;
            }
        }
    }
    cout << counter;
    return 0;
}