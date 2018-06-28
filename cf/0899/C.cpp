#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve_for(int N, ll targ){
    vector<int> ans;
    while(targ){
        while(N > targ){
            N--;
        }
        targ -= N;
        ans.push_back(N);
        N--;
    }

    cout << ans.size();
    for(int i : ans){
        cout << " " << i;
    }
}

int main() {
    ll N;
    cin >> N;

    ll total = N * (N + 1) / 2;

    cout << total % 2 << "\n";
    solve_for(N, total / 2);
}