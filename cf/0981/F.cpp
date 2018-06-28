#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, L;

vector<ll> men, women;

bool check(ll len){
    int lft = 0, rht = 3 * N - 1;
    for(int a = 0; a < N; a++){
        int lbnd = lower_bound(women.begin() + lft, women.begin() + rht + 1, men[a] - len) - women.begin();
        int rbnd = upper_bound(women.begin() + lft, women.begin() + rht + 1, men[a] + len) - women.begin() - 1;

        if(lbnd > rbnd){
            //no possible choice
            return false;
        }

        lft = lbnd + 1;
        rht = rbnd + 1;
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L;

    for(int a = 0; a < N; a++){
        int pos;
        cin >> pos;
        men.push_back(pos);
    }

    for(int a = 0; a < N; a++){
        int pos;
        cin >> pos;
        women.push_back(pos - L);
        women.push_back(pos);
        women.push_back(pos + L);
    }

    sort(allof(men));
    sort(allof(women));

    ll lo = 0, hi = L;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;
}
