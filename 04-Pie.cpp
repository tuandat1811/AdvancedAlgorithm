#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAX = 10000;
int N, F;
double V[MAX];
double ans;

bool check(double val) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += floor(V[i] / val);
    }
    return sum >= F + 1;
}

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> F;
        for (int i = 1; i <= N; i++) {
            double p;
            cin >> p;
            V[i] = PI * p * p;
        }
        sort(V + 1, V + N + 1);
        double L, R, M;
        L = 0;
        R = V[N];
        while (R - L > 1e-6) {
            double M = (L + R) / 2;
            if (check(M)) {
                ans = M;
                L = M;
            }
            else {
                R = M;
            }
        }

        printf("%6lf\n", ans);
    }
}

int main() {
    solve();
    return 0;
}
