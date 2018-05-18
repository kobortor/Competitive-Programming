#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
int N;
int dsu[MAXN];
int sz[MAXN];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

multiset<int> ms;
void merge(int x){
    //x and x + 1
    int fu = find(x);
    int fv = find(x+1);

    if(sz[fu]){
        ms.erase(ms.find(sz[fu]));
    }
    if(sz[fv]){
        ms.erase(ms.find(sz[fv]));
    }

    dsu[fu] = fv;
    sz[fv] += sz[fu];

    if(sz[fv]){
        ms.insert(sz[fv]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < MAXN; a++){
        dsu[a] = a;
        sz[a] = (a & 1);
    }

    map<int, vector<int>> mp;
    mp[0];

    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        mp[x+1].push_back(a);
    }
    
    pii best = pii(-1, 0);

    for(auto & au : mp){
        for(int i : au.second){
            sz[2 * i + 1] = 1;
            ms.insert(1);
            merge(2 * i);
            merge(2 * i + 1);
        }
        if(!ms.empty() && *ms.begin() == *prev(ms.end())){
            best = max(best, pii(ms.size(), -au.first));
        }
    }
    cout << -best.second;
}
