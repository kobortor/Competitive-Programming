#include<bits/stdc++.h>

// Created by kobortor On 09:57:44 on 16-06-2023

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
        int n;
        cin >> n;

        if (n >= 5) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
}
