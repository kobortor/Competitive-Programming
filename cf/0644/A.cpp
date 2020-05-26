#include<bits/stdc++.h>

// Created by kobortor On 01:56:00 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int ans[101][101];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;

    int dem = 1, rep = 2;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if ((i - j) % 2 == 0 && dem <= n) {
                ans[i][j] = dem;
                dem += 2;
            }
            if ((i - j) % 2 != 0 && rep <= n) {
                ans[i][j] = rep;
                rep += 2;
            }
        }
    }

    if (dem <= n || rep <= n) {
        cout << -1;
    } else {
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
