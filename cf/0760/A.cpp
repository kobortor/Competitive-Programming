#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int m, d;
    cin >> m >> d;

    int weeks = 1;
    for (int a = 1; a <= days[m]; a++) {
        if (d == 8) {
            weeks++;
            d = 1;
        }
        d++;
    }

    cout << weeks;
}
