#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int mx = 0, mn = 999, sum = 0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
        sum += x;
    }
    cout << (sum - mn - mx) / (N - 2);
}