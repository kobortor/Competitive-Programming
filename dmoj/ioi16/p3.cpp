#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;
const ll INF = 1e18;

ll N, C;
ll L[MAXN];

pll LDadd[MAXN]; //<add, sub>
pll LDsub[MAXN]; //<sub, add>

bool check(ll Q){
    ll L1 = -INF, R1 = INF; //For L1 <= La + Lb <= R1
    ll L2 = -INF, R2 = INF; //For L2 <= La - Lb <= R2

    ll maxadd1 = -INF, maxadd2 = -INF;
    ll minsub1 = INF, minsub2 = INF;

    ll CsubQ = C - Q;

    //(L[i] - L[j]) + D[j] + D[i] > Q
    //(L[i] + D[i]) - Q > (L[j] - D[j])
    for(int i = 0, j = 0; i < N; i++){
        while(j < N && LDadd[i].first - Q > LDsub[j].first){
            if(LDsub[j].second > maxadd1){
                maxadd2 = maxadd1;
                maxadd1 = LDsub[j].second;
            } else if (LDsub[j].second > maxadd2){
                maxadd2 = LDsub[j].second;
            }

            if(LDsub[j].first < minsub1){
                minsub2 = minsub1;
                minsub1 = LDsub[j].first;
            } else if (LDsub[j].first < minsub2){
                minsub2 = LDsub[j].first;
            }

            j++;
        }

        if(LDadd[i].first - LDadd[i].second > Q && LDadd[i].first == maxadd1){
            L1 = max(L1, maxadd2 + LDadd[i].first + CsubQ);
            L2 = max(L2, maxadd2 - LDadd[i].second + CsubQ);
        } else {
            L1 = max(L1, maxadd1 + LDadd[i].first + CsubQ);
            L2 = max(L2, maxadd1 - LDadd[i].second + CsubQ);
        }

        if(LDadd[i].first - LDadd[i].second > Q && LDadd[i].second == minsub1){
            R1 = min(R1, minsub2 + LDadd[i].second - CsubQ);
            R2 = min(R2, minsub2 - LDadd[i].first - CsubQ);
        } else {
            R1 = min(R1, minsub1 + LDadd[i].second - CsubQ);
            R2 = min(R2, minsub1 - LDadd[i].first - CsubQ);
        }
    }

    for(int a = 0, sl = 0, sr = 0, al = N - 1, ar = N - 1; a < N; a++){
        while(sl < N && L[a] - L[sl] > R2){
            sl++;
        }

        while(sr < N && L[a] - L[sr] >= L2){
            sr++;
        }

        while(ar >= 0 && L[a] + L[ar] > R1){
            ar--;
        }

        while(al >= 0 && L[a] + L[al] >= L1){
            al--;
        }

        if(al >= ar || sl >= sr){
            continue;
        }

        if(al < sl){
            if(sl <= ar){
                return true;
            }
        } else if(al + 1 < sr){ //sl <= ar
            return true;
        }
    }

    return false;
}

long long find_shortcut(int n, int l[], int d[], int c){
    N = n;
    C = c;
    L[0] = 0;

    ll maxprv = d[0], maxdist = 0;
    for(int a = 1; a < n; a++){
        L[a] = L[a - 1] + l[a - 1];

        maxdist = max(maxdist, d[a] + maxprv + l[a - 1]);
        maxprv = max(maxprv + l[a - 1], (ll)d[a]);
    }

    for(int a = 0; a < n; a++){
        LDadd[a].first = L[a] + d[a];
        LDadd[a].second = L[a] - d[a];

        LDsub[a].first = LDadd[a].second;
        LDsub[a].second = LDadd[a].first;
    }

    sort(LDadd, LDadd + n);
    sort(LDsub, LDsub + n);

    ll lo = 0, hi = maxdist;
    
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
