#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    int rhtQ = count(allof(s), 'Q');
    int lftQ = 0;
    int ans = 0;

    for (char c : s) {
        if (c == 'Q') {
            lftQ++;
            rhtQ--;
        } else if (c == 'A') {
            ans += lftQ * rhtQ;
        }
    }
    cout << ans;
}
