#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int arr[5];
    cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    string s;
    cin >> s;

    int ans = 0;
    for (char c : s) {
        ans += arr[c - '0'];
    }

    cout << ans;
}
