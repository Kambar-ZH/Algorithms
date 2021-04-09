#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, f;
    cin >> n >> s >> f;
    int matrix[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int big_num(10000);

    int pos[n], node[n], min(0), index_min(0);
    for (int i = 0; i < n; ++i)
    {                     // заполняем путь к вершине большими числами, желательно взять биг_нам ещё больше, но и так ок.
        pos[i] = big_num; // а все вершины помечаем как "непройденные"
        node[i] = 0;
    }
    pos[s - 1] = 0; // назначаем какую-то вершину началом алгоритма, узлом ( или так не говорят, хз)
    for (int i = 0; i < n - 1; ++i)
    { // основной цикл
        min = big_num;
        for (int j = 0; j < n; ++j)
        { // находим вершину с минимальным к ней расстоянием, на первом шаге это будет узел
            if (!node[j] && pos[j] < min)
            {
                min = pos[j];
                index_min = j;
            }
        }
        node[index_min] = true; // помечаем выбранную вершину как пройденную
        for (int j = 0; j < n; ++j)
        { // цикл, в котором мы даем всем вершинам, смежным с выбранной вес пути к ней
            if (!node[j] && matrix[index_min][j] > 0 && pos[index_min] != big_num && pos[index_min] + matrix[index_min][j] < pos[j])
            {
                pos[j] = pos[index_min] + matrix[index_min][j];
            } // условие такое, если эта вершина не пройденная и она смежна с выбранной и если сумма веса выбранной вершины и ребра к текущей будет меньше, чем
        }     // вес текущей на данный момент, то  - меняем значение веса текущей вершины.
    }

    ( pos[f - 1] == big_num) ? cout << -1 << endl : cout << pos[f - 1] << "\n"; // теперь у нас в pos минимальные расстояния от выбранного узла к любой другой вершине

    cout << endl;
    return 0;
}