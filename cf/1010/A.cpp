#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;
int A[MAXN];
int B[MAXN];

bool check(double fuel){
    for(int a = 1; a <= N; a++){
        fuel -= (fuel + M) / A[a];
        fuel -= (fuel + M) / B[a == N ? 1 : a + 1];
    }
    return fuel >= 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> A[a];
    }

    for(int a = 1; a <= N; a++){
        cin >> B[a];
    }

    if(!check(2e9)){
        cout << -1;
        return 0;
    }

    double lo = 0, hi = 1e9;
    for(int a = 0; a < 100; a++){
        double mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(10) << lo << endl;
}
