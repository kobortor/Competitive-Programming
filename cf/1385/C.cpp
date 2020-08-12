#include<bits/stdc++.h>

// Created by kobortor On 16:46:32 on 11-08-2020

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

        vector<int> a(n);
        for (int &ai : a) cin >> ai;

        int i = a.size() - 1;
        while (i && a[i - 1] >= a[i]) i--;
        while (i && a[i - 1] <= a[i]) i--;

        cout << i << '\n';
    }
}
