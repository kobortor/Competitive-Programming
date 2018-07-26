#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int valid(int n, int inputSeq[]){
    set<int> found;
    int cyc = -1;
    for(int a = 0; a < n; a++){
        if(!found.insert(inputSeq[a]).second){
            return false;
        }
        if(inputSeq[a] <= n){
            if(cyc == -1){
                cyc = (inputSeq[a] - 1 - a + n) % n;
            } else if (cyc != (inputSeq[a] - 1 - a + n) % n){
                return false;
            }
        }
    }

    return true;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]){
    int cyc = 0;
    vector<pii> vec = {{n, -1}};
    for(int a = 0; a < n; a++){
        if(gondolaSeq[a] <= n){
            cyc = (gondolaSeq[a] - 1 - a + n) % n;
        } else {
            vec.emplace_back(gondolaSeq[a], a);
        }
    }

    for(int a = 0; a < n; a++){
        gondolaSeq[a] = (a + cyc) % n + 1;
    }

    sort(allof(vec));
    for(int a = 1; a < (int)vec.size(); a++){
        for(int b = vec[a - 1].first + 1; b <= vec[a].first; b++){
            replacementSeq[b - n - 1] = gondolaSeq[vec[a].second];
            gondolaSeq[vec[a].second] = b;
        }
    }
    return vec.back().first - n;
}

const ll mod = 1e9 + 9;
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

int countReplacement(int n, int inputSeq[]){
    if(!valid(n, inputSeq)){
        return 0;
    }


    vector<pii> vec = {{n, -1}};
    for(int a = 0; a < n; a++){
        if(inputSeq[a] > n){
            vec.emplace_back(inputSeq[a], a);
        }
    }

    sort(allof(vec));

    ll ans = (int)vec.size() == n + 1 ? n : 1;

    for(int a = 1; a < (int)vec.size(); a++){
        ans = ans * qpow(vec.size() - a, vec[a].first - vec[a - 1].first - 1) % mod;
    }

    return ans;
}
