#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;
    for (int a = 1; a * (a + 1) / 2 <= n; a++) {
        cout << s[a * (a + 1) / 2 - 1];
    }

}
