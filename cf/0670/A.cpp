#include<bits/stdc++.h>

// Created by kobortor On 23:36:37 on 25-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int f(int n) {
    return (n / 7) * 2 + max(0, n % 7 - 5);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    cout << f(n) << " " << min(2, n) + f(max(n - 2, 0));
}
