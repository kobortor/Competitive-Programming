#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, ans = 0;
    cin >> N;

    ans += N / 100;
    N %= 100;

    ans += N / 20;
    N %= 20;

    ans += N / 10;
    N %= 10;

    ans += N / 5;
    N %= 5;

    ans += N;

    cout << ans;
}
