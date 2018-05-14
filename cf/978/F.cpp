#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, K;
pii stu[MAXN];
int fight[MAXN];
int out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 0; a < N; a++){
        cin >> stu[a].first;
        stu[a].second = a;
    }

    for(int a = 0; a < K; a++){
        int u, v;
        cin >> u >> v;
        u--; v--;

        if(stu[u].first > stu[v].first) fight[u]++;
        if(stu[v].first > stu[u].first) fight[v]++;
    }

    sort(stu, stu + N);
    for(int a = 0, bk = 0; a < N; a++){
        while(stu[bk].first < stu[a].first){
            bk++;
        }
        out[stu[a].second] = bk - fight[stu[a].second];
    }
    for(int a = 0; a < N; a++){
        cout << out[a] << " ";
    }
}
