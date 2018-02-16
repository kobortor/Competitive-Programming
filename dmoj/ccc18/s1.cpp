#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }
    sort(arr, arr + N);
    double best = 1e15;
    for(int a = 1; a + 1 < N; a++){
        best = min(best, (arr[a] - arr[a - 1]) / 2.0 + (arr[a + 1] - arr[a]) / 2.0);
    }
    cout << fixed << setprecision(1) << best;
}
