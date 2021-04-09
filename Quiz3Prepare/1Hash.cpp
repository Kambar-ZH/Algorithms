int prime = 31;
string s;
cin >> s;
string t;
cin >> t;
int m = t.length();
vt<int> hash2(m), power;
int p = 1;
For(i, m) {
    power.push_back(p);
    p *= prime; 
}
hash2[0] = (t[0] - 'a' + 1);
qFor(i, 1, m) {
    hash2[i] = hash2[i - 1] + (t[i] - 'a' + 1) * power[i];
}
int n = s.length();
int hash = 0;
For(i, n) {
    hash += (s[i] - 'a' + 1) * power[i]; 
}
int cnt = 0;
if (hash == hash2[n - 1]) {
    cnt++;
}
for (int i = n; i < m; ++i) {
    int tmp = hash2[i] - hash2[i - n];
    int tmp2 = hash * power[i - n + 1];
    if (tmp == tmp2) {
        cnt++;
    }
}