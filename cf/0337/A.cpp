#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100;

int N, M;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < M; a++){
        cin >> arr[a];
    }
    sort(arr, arr + M);

    int best = 1e9;
    for(int a = 0; a + N - 1 < M; a++){
        best = min(best, arr[a + N - 1] - arr[a]);
    }
    cout << best;
}
