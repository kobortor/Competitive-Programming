#include<bits/stdc++.h>

// Created by kobortor On 11:20:39 on 14-06-2023

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
        string s;
        cin >> n >> s;
        char ch = '!';
        for (char c : s) {
            if (ch == '!') {
                ch = c;
            } else if (ch == c) {
                cout << c;
                ch = '!';
            }
        }
        cout << "\n";
    }
}
