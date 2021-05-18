#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
unsigned long long N, M;
unsigned long long h[MAX];
unsigned long long ans;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> h[i];
}

bool check(unsigned long long m) {
    unsigned long long sum = 0;
    for (int i = 1; i <= N; i++) {
        if (h[i] > m) sum += h[i] - m;
    }
    return sum >= M;
}

void solve() {
    sort(h + 1, h + 1 + N);

    unsigned long long l, r, m;
    l = 0; r = h[N];
    while (l < r - 1) {
        m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            l = m;
        }
        else r = m;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}