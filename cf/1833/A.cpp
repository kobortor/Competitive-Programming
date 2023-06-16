#include<bits/stdc++.h>

// Created by kobortor On 10:17:37 on 15-06-2023

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
        string s;
        cin >> n >> s;
        set<string> st;
        for (int i = 0; i + 1 < n; i++) {
            st.insert(s.substr(i, 2));
        }
        cout << st.size() << "\n";
    }
}
