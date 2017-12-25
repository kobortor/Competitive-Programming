#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

vector<int> adj1[MAXN];
int sz1[MAXN];

int eid = 1;
pii euler1[MAXN];

set<pii> ranges;

void euler_tour(int pos, int par){
    euler1[pos].first = eid++;
    for(int i : adj1[pos]){
        if(i == par){
            continue;
        }
        euler_tour(i, pos);
    }
    euler1[pos].second = eid - 1;
    sz1[pos] = eid - euler1[pos].first;
    ranges.insert(euler1[pos]);
}

pii euler2[MAXN];
vector<int> adj2[MAXN];
int sz2[MAXN];

int ans = 0;

void dfs2(int pos, int par){
    sz2[pos] = 1;
    euler2[pos].first = euler1[pos].first;
    euler2[pos].second = euler1[pos].first;

    for(int i : adj2[pos]){
        if(i == par){
            continue;
        }
        dfs2(i, pos);
        sz2[pos] += sz2[i];

        euler2[pos].first = min(euler2[pos].first, euler2[i].first);
        euler2[pos].second = max(euler2[pos].second, euler2[i].second);
    }
    if(pos != 1 && euler2[pos].second - euler2[pos].first + 1 == sz2[pos]){
        ans += ranges.count(euler2[pos]);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    
    for (int a = 2; a <= N; a++) {
        int x;
        cin >> x;
        adj1[x].push_back(a);
        adj1[a].push_back(x);
    }

    for (int a = 2; a <= N; a++) {
        int x;
        cin >> x;
        adj2[x].push_back(a);
        adj2[a].push_back(x);
    }

    euler_tour(1, -1);
    dfs2(1, -1);
    cout << ans;
}