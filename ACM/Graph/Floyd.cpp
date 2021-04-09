#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int SIZE;
    cin >> SIZE;
    vector< vector<int> > adjacency_matrix(SIZE, vector<int>(SIZE)); 
    for (int row = 0; row < SIZE; ++row)
    {
        for (int column = 0; column < SIZE; ++column)
        {
            cin >> adjacency_matrix[row][column];
        }
    }
    for (int intermediate = 0; intermediate < SIZE; ++intermediate)
    {
        for (int straight_row = 0; straight_row < SIZE; ++straight_row)
        {
            for (int straight_column = 0; straight_column < SIZE; ++straight_column)
            {
                if (adjacency_matrix[straight_row][straight_column] > adjacency_matrix[straight_row][intermediate] + adjacency_matrix[intermediate][straight_column])
                {
                    adjacency_matrix[straight_row][straight_column] = adjacency_matrix[straight_row][intermediate] + adjacency_matrix[intermediate][straight_column];
                }
            }
        }
    }
    for (int row = 0; row < SIZE; ++row)
    {
        for (int column = 0; column < SIZE; ++column)
        {
            cout << adjacency_matrix[row][column] << " ";
        }
        cout << "\n";
    }
    return 0;
}