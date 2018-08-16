#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int ask(int x){
    cout << x << endl;
    int ans;
    cin >> ans;

    if(ans == 0){
        exit(0);
    }

    return ans;
}

int M, N;
vector<int> seq;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M >> N;

    for(int a = 0; a < N; a++){
        seq.push_back(ask(M) == -1);
    }

    int lo = 1, hi = M;
    int cur = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if((ask(mid) == -1) == seq[cur]){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }

        cur = (cur + 1) % N;
    }

    ask(lo);
}
