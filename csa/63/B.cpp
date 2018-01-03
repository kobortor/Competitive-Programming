#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


double S, K;
long long Q;

vector<double> deals;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> S >> Q >> K;
    for(int a = 0; a < Q; a++){
        double x;
        cin >> x;
        deals.push_back(1.00 + x / 100.0);
    }
    sort(deals.begin(), deals.end());
    
    for(double x : deals){
        S = max(S * x, S + K);
    }
    cout << setprecision(10) << fixed << S;
}