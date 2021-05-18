#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAX = 1000000;
ll max_area=0;
ll tp;
ll area_top;
ll h, n;
ll now;
int solve(){	
	int i=0;
	stack<ll> s;
	ll ht[MAX];
	cin>>n;
	if (n==0) return -1;	
	for (ll i = 0; i < n; i++){
			cin>>h;
			ht[i] = h;
		}
	max_area=0;
	while (i<n){
		if (s.empty() or ht[s.top()] <= ht[i]){
			s.push(i++);
		}
		else {
			tp= s.top();
			s.pop();
			now= ht[i]*(s.empty()?i:i-s.top()-1);
			if (max_area<now){
				max_area=now;
			}
		}
	}
	while (!s.empty()){
		tp = s.top();
        s.pop();
        now = ht[i]*( s.empty()? i:i-s.top()-1 );
        if(max_area < now)
        max_area = now;
	}
	cout<< max_area <<endl;
	return 0;
}

int main(){
	while(1){
		if (solve()==-1) {
			break;
		}
	}
	solve();
}
