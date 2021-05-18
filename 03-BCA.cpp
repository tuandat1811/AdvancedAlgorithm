#include<bits/stdc++.h>
using namespace std;
const int MAX = 35;
int m;
int n; 
vector<int> t[MAX];
int x[MAX];
int load[MAX]; 
bool c[MAX][MAX];
int best;
bool found;

void input() {
	cin >> m >> n;

}
bool check(int g, int k) {
	for (int i = 1;i <= k - 1;i++) {
		if (c[i][k] && x[i] == g) {
			return false;
		}
	}
}
void solution() {
	found = true;
	int max_load = 0;
	for (int i = 1;i <= m; i++) {
		max_load = max(max_load, load[i]);
		best = min(best, max_load);
	}
}
void TRY(int k) {
	for (int i = 0; i < t[k].size(); i++) {
		int g = t[k][i];
		if (check(g, k)) {
			x[k] = g;
			load[g]++;
			if (k == n) solution();
			else {
				if (load[g] < best) TRY(k + 1);
			}
			load[g]--;
		}
	}
}
int main() {

}