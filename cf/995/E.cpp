#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int u, v, mod;

unordered_map<int, int> mp1, mp2;
queue<int> q1, q2;

ll inv(ll x){
    ll ans = 1;
    ll y = mod - 2;

    while(y){
        if(y & 1){
            ans = ans * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

int apply(int x, int method){
    if(method == 1){
        return (x + 1) % mod;
    } else if (method == 2){
        return (x + mod - 1) % mod;
    } else {
        return inv(x);
    }
}

int revapply(int x, int method){
    if(method <= 2){
        return apply(x, 3 - method);
    } else {
        return apply(x, 3);
    }
}

void solvefor(int x){
    vector<int> vecu, vecv;
    int tmp = x;

    while(tmp != u){
        int val = mp1[tmp];
        vecu.push_back(val);

        tmp = revapply(tmp, val);
    }

    tmp = x;

    while(tmp != v){
        int val = mp2[tmp];
        vecv.push_back(val);

        tmp = apply(tmp, val);
    }

    cout << vecu.size() + vecv.size() << "\n";

    while(!vecu.empty()){
        cout << vecu.back() << " ";
        vecu.pop_back();
    }

    for(int i : vecv){
        cout << i << " ";
    }

    exit(0);
}

void check1(int x, int method){
    auto au = mp1.insert({x, method});
    if(au.second){
        au.first->second = method;

        if(mp2.count(x)){
            solvefor(x);
        }

        q1.push(x);
    }
}

void check2(int x, int method){
    auto au = mp2.insert({x, method});
    if(au.second){
        au.first->second = method;

        if(mp1.count(x)){
            solvefor(x);
        }

        q2.push(x);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> u >> v >> mod;

    q1.push(u);
    q2.push(v);

    mp1[u] = -1;
    mp2[v] = -1;

    while(true){
        if(!q1.empty()){
            int fr = q1.front();
            q1.pop();

            check1(apply(fr, 1), 1);
            check1(apply(fr, 2), 2);
            check1(apply(fr, 3), 3);
        }

        if(!q2.empty()){
            int fr = q2.front();
            q2.pop();

            check2(revapply(fr, 1), 1);
            check2(revapply(fr, 2), 2);
            check2(revapply(fr, 3), 3);
        }
    }
}
