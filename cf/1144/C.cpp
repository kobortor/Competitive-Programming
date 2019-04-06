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

    vector<int> v(n);
    for (int a = 0; a < n; a++){
        cin >> v[a];
    }

    sort(allof(v));

    for (int a = 1; a + 1 < n; a++){
        if (v[a - 1] == v[a] && v[a] == v[a + 1]){
            cout << "NO";
            return 0;
        }
    }

    vector<int> inc, dec;
    for (int a = 0; a < n; a++){
        if (a != 0 && v[a - 1] == v[a]){
            dec.push_back(v[a]);
        } else {
            inc.push_back(v[a]);
        }
    }

    reverse(allof(dec));

    cout << "YES\n";

    cout << inc.size() << "\n";
    for (int i : inc) cout << i << " ";
    cout << "\n";

    cout << dec.size() << "\n";
    for (int i : dec) cout << i << " ";
    cout << "\n";
}
