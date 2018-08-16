#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string S, T;
    cin >> S >> T;
    S += S;

    cout << (S.find(T) == string::npos ? "No" : "Yes");
}
