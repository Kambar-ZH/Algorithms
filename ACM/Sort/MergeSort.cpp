#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &data, int start, int end)
{
    if (end - start < 2)
    {
        return;
    }
    if (end - start == 2)
    {
        if (data[start] > data[start + 1])
        {
            swap(data[start], data[start + 1]);
        }
        return;
    }
    merge_sort(data, start, start + (end - start) / 2);
    merge_sort(data, start + (end - start) / 2, end);
    vector<int> sorted_data;
    int start_2 = start;
    int middle = start + (end - start) / 2;
    int middle_2 = middle;
    while (sorted_data.size() < end - start)
    {
        if (start_2 >= middle || (middle_2 < end && data[middle_2] < data[start_2]))
        {
            sorted_data.push_back(data[middle_2]);
            middle_2++;
        }
        else
        {
            sorted_data.push_back(data[start_2]);
            start_2++;
        }
    }
    for (int i = start; i < end; ++i)
    {
        data[i] = sorted_data[i - start];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> data;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        data.push_back(x);
    }
    merge_sort(data, 0, data.size());
    for (int i = 0; i < n; ++i)
    {
        cout << data[i] << " ";
    }
    return 0;
}