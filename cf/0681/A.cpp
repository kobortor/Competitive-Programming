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

    while (n--) {
        string name;
        int before, after;
        cin >> name >> before >> after;

        if (before >= 2400 && after > before) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
