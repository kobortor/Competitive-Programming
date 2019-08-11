#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    int cnt = count(allof(s), '4') + count(allof(s), '7');
    if (cnt == 4 || cnt == 7) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
