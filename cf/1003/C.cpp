#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int N, K;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    double ans = 0;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    for(int a = 1; a <= N; a++){
        int tot = 0;
        for(int b = a; b <= N; b++){
            tot += arr[b];
            if(b - a + 1 >= K){
                ans = max(ans, (double)tot / (b - a + 1));
            }
        }
    }

    cout << fixed << setprecision(15) << ans;
}
