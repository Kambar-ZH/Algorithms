#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000];     //массив
int tree[400004];  //дерево отрезков. в вершинах хранятся минимумы

void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);    //сохраняем минимум вместо суммы
    }
}

//Запрос минимума
int get_min(int l, int r, int v, int tl, int tr) {
    //вариант 1
    if (l <= tl && tr <= r) {
        return tree[v];
    }

    //вариант 2
    if (tr < l || r < tl) {
        return INT_MAX;     //Значение, которое не повлияет на общий минимум
    }

    //вариант 3
    int tm = (tl + tr) / 2;
    return min(get_min(l, r, v * 2,     tl,     tm),    //минимум вместо суммы.
               get_min(l, r, v * 2 + 1, tm + 1, tr));
}

void update(int idx, int val, int v, int tl, int tr) {
    //вариант 1
    if (idx <= tl && tr <= idx) {       //То же, что и idx == tl == tr
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
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);    //минимум вместо суммы.
}

int main() {
    //Ввод массива...

    build_tree(1, 0, n - 1);    //параметры корня дерева.
                                //все запросы должны вызываться для этих параметров.

    //Можно делать запросы вида get_min(l, r, 1, 0, n - 1) и update(idx, val, 1, 0, n - 1);
}