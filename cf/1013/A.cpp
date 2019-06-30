#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int tot = 0;
    for (int a = 0; a < N; a++) {
        int x;
        cin >> x;
        tot += x;
    }
    for (int a = 0; a < N; a++) {
        int x;
        cin >> x;
        tot -= x;
    }

    if (tot < 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}
