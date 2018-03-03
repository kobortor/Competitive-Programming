#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 21;

double vals[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> vals[a];
    }
    sort(vals, vals + N);
    for(int a = 1; a < N; a++){
        vals[a] = (vals[a - 1] + vals[a]) / 2.0;
    }
    cout << fixed << setprecision(9) << vals[N - 1];
}
