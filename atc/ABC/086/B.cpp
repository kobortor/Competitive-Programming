#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string a, b;
    cin >> a >> b;
    int n = stoi(a + b);
    int sq = sqrt(n);
    cout << (sq * sq == n ? "Yes" : "No");
}
