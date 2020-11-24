#include<bits/stdc++.h>

// Created by kobortor On 02:19:34 on 24-11-2020

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
        int ans = 0;

        int b1 = 0, b2 = 0;
        string s;
        cin >> s;
        for (char c : s) {
            if (c == '(') {
                b1++;
            } else if (c == '[') {
                b2++;
            } else if (c == ')') {
                if (b1) {
                    b1--;
                    ans++;
                }
            } else if (c == ']') {
                if (b2) {
                    b2--;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}
