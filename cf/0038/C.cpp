#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, L;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int ans = 0;
    for(int x = L; x <= 100; x++){
        int tmp = 0;
        for(int a = 1; a <= N; a++){
            tmp += arr[a] / x * x;
        }
        ans = max(ans, tmp);
    }

    cout << ans;
}
