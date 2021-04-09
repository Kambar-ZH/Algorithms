#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000];     //массив
int tree[400004];  //дерево отрезков. в вершинах хранятся суммы

//Построение дерева по изначальному массиву.
//v - номер текущей вершины; tl, tr - границы соответствующего отрезка
void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];    //сумма отрезка из одного элемента равна этому элементу
    } else {
        //tm - средний элемент отрезка.
        //отрезок разбивается на два отрезка [tl; tm], [tm + 1; tr]
        int tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

//Запрос суммы
//l, r - границы запроса;
//v - номер текущей вершины; tl, tr - границы соответствующего отрезка
int get_sum(int l, int r, int v, int tl, int tr) {
    //вариант 1
    if (l <= tl && tr <= r) {
        return tree[v];
    }

    //вариант 2
    if (tr < l || r < tl) {
        return 0;
    }

    //вариант 3
    int tm = (tl + tr) / 2;
    return get_sum(l, r, v * 2,     tl,     tm)
         + get_sum(l, r, v * 2 + 1, tm + 1, tr);
}

//Запрос модификации
//idx - индекс элемента, val - новое значение
//v - номер текущей вершины; tl, tr - границы соответствующего отрезка
void update(int idx, int val, int v, int tl, int tr) {
    //вариант 1
    if (idx <= tl && tr <= idx) {    //То же, что и idx == tl == tr
        a[idx] = val;
        tree[v] = val;
        return;
    }

    //вариант 2
    if (tr < idx || idx < tl) {
        return;
    }

    //вариант 3
    int tm = (tl + tr) / 2;
    update(idx, val, v * 2,     tl,     tm);
    update(idx, val, v * 2 + 1, tm + 1, tr);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int main() {
    //Ввод массива...
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int l, r;
    cin >> l >> r;
    build_tree(1, 0, n - 1);    //параметры корня дерева.
                                //все запросы должны вызываться для этих параметров.

    int result = get_sum(l, r, 1, 0, n - 1);
    cout << result;
    //Можно делать запросы вида get_sum(l, r, 1, 0, n - 1) и update(idx, val, 1, 0, n - 1);
}