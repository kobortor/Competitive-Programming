#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N;

pii tasks[MAXN];

double dp[MAXN][MAXN];

bool check(double avg){
    for(int a = 0; a < MAXN; a++){
        fill(dp[a], dp[a] + MAXN, 1e15);
    }

    dp[0][0] = 0;

    for(int a = 1; a <= N; a++){
        int bk = a;

        while(bk + 1 <= N && tasks[a].first == tasks[bk + 1].first){
            bk++;
        }

        int tot = bk - a + 1;
        double totpower = 0;

        for(int i = a; i <= bk; i++){
            totpower += tasks[i].first - tasks[i].second * avg;
        }

        for(int b = 0; b <= a; b++){
            double power = totpower;
            for(int i = 0; i <= b && i <= tot; i++){
                int ni = b - i + (tot - i);
                dp[bk][ni] = min(dp[bk][ni], dp[a - 1][b] + power);
                power -= tasks[a + i].first - tasks[a + i].second * avg;
            }
        }

        a = bk;
    }

    return *min_element(dp[N], dp[N] + MAXN) <= 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> tasks[a].first;
    }
    for(int a = 1; a <= N; a++){
        cin >> tasks[a].second;
    }

    sort(tasks + 1, tasks + N + 1, [](pii p1, pii p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        } else {
            return p1.first > p2.first;
        }
    });

    double lo = 0.01, hi = 2e8;
    for(int a = 0; a < 50; a++){
        double mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << (ll)ceil(lo * 1000);
}
