#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string names[3] = {"chest", "biceps", "back"};
int ans[3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	int N;
	cin >> N;
	for(int a = 0; a < N; a++){
		int x;
		cin >> x;
		ans[a % 3] += x;
	}
	cout << names[max_element(ans, ans + 3) - ans];
}
