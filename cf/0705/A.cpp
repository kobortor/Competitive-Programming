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
    for (int a = 0; a < n; a++) {
        if (a % 2 == 0) {
            cout << "I hate ";
        } else {
            cout << "I love ";
        }

        if (a == n - 1) {
            cout << "it";
        } else {
            cout << "that ";
        }
    }
}
