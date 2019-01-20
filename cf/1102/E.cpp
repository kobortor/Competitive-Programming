#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

const int MAXN = 2e5 + 5;

map<int, int> last;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        last[arr[a]] = a;
    }

    ll ans = (mod + 1) / 2;
    for(int a = 1; a <= N;){
        ans = ans * 2 % mod;

        int end = -1;
        do {
            end = max(end, last[arr[a]]);
            a++;
        } while (a <= end);
    }

    cout << ans;
}
