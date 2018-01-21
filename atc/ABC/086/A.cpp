#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll A, B;
    cin >> A >> B;
    cout << (A * B % 2 ? "Odd" : "Even");
}
