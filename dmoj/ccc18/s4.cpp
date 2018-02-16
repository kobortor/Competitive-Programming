#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//constant optimization problem, submit in clang++ on DMOJ to pass

unordered_map<int, ll> solved;
ll solve(int N) {
    if(N == 1){
        return 1;
    }
    if(solved.count(N)){
        return solved[N];
    }
    int sub = 2;
    ll ans = 0;
    while(sub <= N){
        int wt = N / sub;
        //find sub such that sub * wt > N
        int nxtsub = N / wt + 1;
        ans += ll(nxtsub - sub) * solve(wt);
        sub = nxtsub;
    }
    solved[N] = ans;
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll N;
    cin >> N;
    cout << solve(N) << "\n";
}
