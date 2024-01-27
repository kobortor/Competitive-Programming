#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> solve(int n) {
    if (n == 1) {
        return {pii(1, 3)};
    }

    map<int, int> map1;
    map1[1] = 1;
    map1[2] = 3;
    map1[3] = 2;
    vector<pii> tmp = solve(n - 1);
    vector<pii> ans;
    for (pii p : tmp) {
        p.first = map1[p.first];
        p.second = map1[p.second];
        ans.push_back(p);
    }

    ans.push_back(pii(1, 3));

    map<int, int> map2;
    map2[1] = 2;
    map2[2] = 1;
    map2[3] = 3;
    for (pii p : tmp) {
        p.first = map2[p.first];
        p.second = map2[p.second];
        ans.push_back(p);
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pii> ans = solve(n);
    cout << ans.size() << "\n";
    for (pii p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}
