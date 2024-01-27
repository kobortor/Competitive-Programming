#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

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

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        while (j + 1 < s.size() && s[j + 1] == s[j]) {
            j++;
        }
        ans = max(ans, j - i + 1);
        i = j;
    }
    cout << ans << endl;
}
