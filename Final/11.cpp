5
1 1 * 
2 2 
3 3 *
4 4 * max(2, 4)
5 5

For(i, n) For(j, n) {
    g[i].push_back({j, formula});
}

vt<int> age(n);
queue<pair<int, int> > p;
p.push({0, -1});
int atleast;
if (start == finish) {cout << 0; return 0;}
while (is) {
    front
    pop
    for (adjacent vert) {
        int tmp = max(atleast, g[v][i]); 
        if (atleast != -1 && d[i] > g[v][i]) {
            d[i] = g[v][i];
            push({i, g[v][i]});
        } else if (d[i] > tmp) {
            d[i] = tmp;
            push({i, d[i]});
        }
    }
}
cout << d[finish];


5
-3 -4 6 3 5
0
-3
-7
-1
2
7

-7 -3 -1 0 2 7
4 2 1 2 5


prefix(n + 1);
for (int i : n) {
    prefix[i] = prefix[i - 1] + a[i - 1];
}
sort(prefix.all());
int mini = MAXN;
For(i, n) {
    int res = prefix[i] - prefix[i - 1];
    mini = min(mini, res);
}
cout << mini;

add
delete
find_prefix

