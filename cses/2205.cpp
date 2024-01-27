#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> solve(int n) {
    if (n == 0) {
        return {{}};
    }
    vector<vector<int>> tmp = solve(n - 1);
    vector<vector<int>> ans;
    for (vector<int> v : tmp) {
        v.push_back(0);
        ans.push_back(v);
    }
    reverse(tmp.begin(), tmp.end());
    for (vector<int> v : tmp) {
        v.push_back(1);
        ans.push_back(v);
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    for (vector<int> v : solve(n)) {
        for (int vi : v) {
            cout << vi;
        }
        cout << "\n";
    }    
}
