#include <iostream>
#include <queue>
using namespace std;
int main() {
    // чтение исходных данных
    int n, v; 
    cin >> n >> v;
    int matrix[n][n]; // матрица смежности
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    queue <int> plan; // план посещения в виде очереди
    plan.push(--v);   // мы нумеруем с 0, а не с 1
    matrix[v][v] = 1; // отмечаем, что эта вершина уже заносилась в план 
    int counter = 1;  // начальную уже сосчитали
    cout << plan.front();
    while (!plan.empty()) { // пока план не пустой
        v = plan.front(); // посещаем следующую по плану вершину 
        plan.pop();       // удаляем ее из плана посещения
        for (int u = 0; u < n; u++) { // перебираем соседние с ней
            if (matrix[v][u] and !matrix[u][u]) { // если новая, то
                plan.push(u);     // добавляем ее в план
                matrix[u][u] = 1; // отмечаем, что уже не новая
                counter++;        // считаем, сколько было вершин
            }
        }
    }
    cout << counter << endl;
}