#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N;
	for(int a = 0; a < N; a++){
		cin >> arr[a];
	}
	int minv = *min_element(arr, arr + N);
	int best = 999999;
	int prv = -999999;
	for(int a = 0; a < N; a++){
		if(arr[a] == minv){
			best = min(best, a - prv);
			prv = a;
		}
	}
	cout << best;
}
