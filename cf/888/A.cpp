#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int arr[1005];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N;
	for(int a = 1; a <= N; a++){
		cin >> arr[a];
	}

	int ans = 0;
	for(int a = 2; a < N; a++){
		if(arr[a - 1] > arr[a] && arr[a] < arr[a + 1]){
			ans++;
		}
		if(arr[a - 1] < arr[a] && arr[a] > arr[a + 1]){
			ans++;
		}
	}
	cout << ans;
}
