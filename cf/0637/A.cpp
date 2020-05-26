#include<bits/stdc++.h>

// Created by kobortor On 01:53:20 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii cnt[1000001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cnt[x] = {cnt[x].first + 1, n};
    }

    cout << max_element(cnt, cnt + 1000001) - cnt;
}
