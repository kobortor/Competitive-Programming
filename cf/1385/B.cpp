#include<bits/stdc++.h>

// Created by kobortor On 14:25:09 on 30-07-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> used(n);
        vector<int> answer;

        for (int i = 0; i < 2 * n; i++) {
            int x;
            cin >> x;
            if (!used[x - 1]) {
                used[x - 1] = true;
                answer.push_back(x);
            }
        }

        for (int a : answer) cout << a << " ";
        cout << "\n";
    }
}
