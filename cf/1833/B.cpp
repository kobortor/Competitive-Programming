#include<bits/stdc++.h>

// Created by kobortor On 10:19:38 on 15-06-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pii> A(n);
        for (int i = 0; i < n; i++) {
            A[i].second = i;
            cin >> A[i].first;
        }
        vector<int> B(n);
        for (int &bi : B) {
            cin >> bi;
        }
        sort(allof(A));
        sort(allof(B));
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[A[i].second] = B[i];
        }
        for (int &aa : ans) {
            cout << aa << " ";
        }
        cout << "\n";
    }
}
