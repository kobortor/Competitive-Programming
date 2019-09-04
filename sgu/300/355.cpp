#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10005;

int N;
int col[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 1; a <= N; a++) {
        col[a] = 1;
        for (int b = 1; b * b <= a; b++) {
            if (a % b == 0) {
                if (b != a) col[a] = max(col[a], col[b] + 1);
                if (a / b != a) col[a] = max(col[a], col[a / b] + 1);
            }
        }
    }

    cout << *max_element(col + 1, col + N + 1) << endl;
    for (int a = 1; a <= N; a++) {
        cout << col[a] << " ";
    }
}
