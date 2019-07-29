#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, vb, vs;
    cin >> n >> vb >> vs;

    vector<int> xi(n);
    for (int &i : xi) cin >> i;

    int xu, yu;
    cin >> xu >> yu;

    pair<double, double> ans = {1e9, 1e9};
    int pos = 0;
    for (int a = 1; a < n; a++) {
        double d1 = (double)xi[a] / vb + hypot(xi[a] - xu, yu) / vs;
        double d2 = hypot(xi[a] - xu, yu) / vs;
        pair<double, double> tmp = {d1, d2};
        if (tmp < ans) {
            ans = tmp;
            pos = a + 1;
        }
    }
    cout << pos;
}
