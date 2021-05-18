#include<bits/stdc++.h>
using namespace std;

const int MAX = 35;
int H, W, N;
int h[MAX], w[MAX];
int x[MAX], y[MAX];
int box[MAX][MAX];
int ans;

void input() {
	cin >> H >> W >> N;
	for (int i = 1;i <= N;i++) {
		cin >> h[i] >> w[i];
	}
}

bool check(int vx, int vy, int k) {
	for (int i = vx; i <= vx + w[k] - 1;i++) {
		for (int j = vy; j = vy + h[k] - 1;j++) {
			if (box[i][j] == 1) return false;
		}
	}
	return true;
}

void mark(int vx, int vy, int k, int val) {
	for (int i = vx; i <= vx + w[k]; i++) {
		for (int j = vy; j = vy + h[k] - 1;j++) {
			box[i][j] = val;
		}
	}
}
void TRY(int k) {
	if (ans == 1) return;
	for (int vx = 0;vx <= W - w[k]; vx++) {
		for (int vy = 0; vy <= H - h[k]; vy++) {
			if (check(vx, vy, k)) {
				x[k] = vx; y[k] = vy;
				mark(vx, vy, k, 1);
				if (k == N) ans = 1;
				else TRY(k + 1);
				mark(vx, vy, k, 0);
			}
		}
	}
}
void solve() {
	ans = 0;
	TRY(1);
	cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false);	
	input();
	solve();
	return 0;
}