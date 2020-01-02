#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<string> v(4);
    cin >> v[0] >> v[1] >> v[2] >> v[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int hashes = 
                (v[i][j] == '#') +
                (v[i][j + 1] == '#') +
                (v[i + 1][j] == '#') +
                (v[i + 1][j + 1] == '#');


            if (hashes != 2) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}
