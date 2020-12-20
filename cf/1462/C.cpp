#include<bits/stdc++.h>

// Created by kobortor On 23:15:55 on 19-12-2020

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
        int x;
        cin >> x;
        string s;
        for (int i = 9; i >= 1; i--) {
            if (i <= x) {
                s += char('0' + i);
                x -= i;
            }
        }
        if (x == 0) {
            reverse(allof(s));
            cout << s << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
