#include <iostream>
using namespace std;

int car_fueling(int a[], int n, int distance)
{
    int refilles_num, current_refill;
    refilles_num = 0;
    current_refill = 0;
    while (current_refill < n - 1)
    {
        int last_refill;
        last_refill = current_refill;
        while (current_refill < n - 1 && a[current_refill + 1] - a[last_refill] <= distance)
        {
            current_refill += 1;
        }
        if (current_refill == last_refill)
        {
            cout << "Impossible";
            return 0;
        }
        if (current_refill < n)
            refilles_num += 1;
        cout << a[current_refill] << " " << refilles_num << endl;
    }
    return refilles_num;
}

int main()
{
    int n, distance;
    cin >> n >> distance; 
    int A[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    int result;
    result = car_fueling(A, n, distance);
    cout << result;
    return 0;
}