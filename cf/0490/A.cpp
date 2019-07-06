#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> kids[4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int a = 1; a <= n; a++) {
        int x;
        cin >> x;
        kids[x].push_back(a);
    }

    int mn = min(min(kids[1].size(), kids[2].size()), kids[3].size());
    cout << mn << "\n";

    for (int a = 0; a < mn; a++) {
        cout << kids[1][a] << " " << kids[2][a] << " " << kids[3][a] << "\n";
    }
}
