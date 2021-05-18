#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, T, mc[2], n_prepare;
ll c[105], len[105];
string p;
string F[105];

void preprocessing() {
    int i = 2;
    F[0] = "0";
    len[0] = 1;
    F[1] = "1";
    len[1] = 1;
    n_prepare = 2;
    while (len[i - 1] < 100000) {
        F[i] = F[i - 1] + F[i - 2];
        len[i] = len[i - 1] + len[i - 2];
        i++;
        n_prepare++;
    }
}

ll algo1(string p, string s) {
    int lenP = p.length(), lenS = s.length();
    ll res = 0;
    if (lenP > lenS) {
        return 0;
    }
    for (int i = 0; i < lenS - lenP + 1; i++) {
        if (p == s.substr(i, lenP)) {
            res++;
        }
    }
    return res;
}

ll algo2(string p, int n) {
    if (c[n] < 0) {
        c[n] = algo2(p, n - 1) + algo2(p, n - 2) + mc[n % 2];
    }
    return c[n];
}

ll solve(string p, int n) {
    ll lenP = p.length();
    if (len[n] < lenP && n < n_prepare) {
        return 0;
    }
    int i = 1;
    while (F[i - 1].length() < lenP) {
        i++;
    }
    c[i - 1] = algo1(p, F[i - 1]);
    c[i] = algo1(p, F[i]);
    string x = F[i].substr(0, lenP - 1);
    string a = F[i - 1].substr(F[i - 1].length() - (lenP - 1));
    string b = F[i].substr(F[i].length() - (lenP - 1));
    mc[i % 2] = algo1(p, a + x);
    mc[(i + 1) % 2] = algo1(p, b + x);
    return algo2(p, n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int i = 0;
    preprocessing();
    while(cin >> n) {
        i++;
        memset(c, -1, sizeof(c));
        cin >> p;
        ll res = solve(p, n);
        cout << "Case " << i << ": " << res << endl;
    }
    return 0;
}