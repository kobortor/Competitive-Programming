#include<bits/stdc++.h>

// Created by kobortor On 16:18:56 on 27-05-2020

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
        int a, b;
        cin >> a >> b;

        int x = max(max(a, b), 2 * min(a, b));

        cout << x * x << "\n";
    }
}
