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

    int sum = 0;
    for (int a = 0, x; a < N; a++) {
        cin >> x;
        sum += x;
    }

    cout << fixed << setprecision(10) << (double) sum / N;
}
