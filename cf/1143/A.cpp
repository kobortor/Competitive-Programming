#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    
    int last0 = 1e9, last1 = 1e9;
    for (int a = 1; a <= n; a++) {
        int x;
        cin >> x;
        if (x) last1 = a;
        else last0 = a;
    }

    cout << min(last0, last1);
}
