#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    int a[n]; // массив для перестановки из n чисел
    for (int i = 0; i < n; i++) cin>> a[i];
    for (int i = n - 2; i >= 0; i--) { 
        if (a[i] < a[i+1]){
            int min = i + 1; // индекс минимального элемента 
            for (int j = i + 2; j < n; j++) {
                if (a[i] < a[j] && a[j] < a[min]) min = j;
            }
            swap(a[i], a[min]);
            reverse(&a[i+1], &a[n]);
            break;
        }
        if (i == 0) reverse(&a[i], &a[n]);
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
// min = 4, from 5 to 6, if (a[5] > a[3] and a[5] < a[4]) min = 5 (4 > 4 and 4 < 5) no
// if (a[6] > a[3] and a[6] < a[4]) (3 > 4 and 3 < 5) no
// swap (a[3], a[4])
// reverse (a[4], a[7])
// example: 1 3 2 4 5 4 3
// 1 3 2 4 5 (<- min) 4 3
// 1 3 2 5 4 4 3 (when we swap the elements)
// 1 3 2 5 3 4 4 (we reverse from i + 1 till the end)