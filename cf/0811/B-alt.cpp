#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//faster method with BIT data structure
//time used is 31ms vs 93ms on the brute force

const int MAXN = 1e4 + 4;
int arr[MAXN];
int out[MAXN];

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    int get(int pos){
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
}ds;


struct query {
    int L, R, X, id;
    bool operator<(const query &q) const {
        return arr[X] < arr[q.X];
    }
};
vector<query> queries;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N, M;
    cin >> N >> M;

    vector<pii> perms;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        perms.push_back({arr[a], a});
    }

    for(int a = 0; a < M; a++){
        query q;
        cin >> q.L >> q.R >> q.X;
        q.id = a;
        queries.push_back(q);
    }

    sort(perms.begin(), perms.end());
    sort(queries.begin(), queries.end());

    int sz = 0;
    for(const query &q : queries){
        while(sz < (int)perms.size() && perms[sz].first < arr[q.X]){
            ds.update(perms[sz].second, 1);
            sz++;
        }
        out[q.id] = (ds.get(q.R) - ds.get(q.L - 1) == q.X - q.L);
    }
    for(int a = 0; a < M; a++){
        cout << (out[a] ? "Yes\n" : "No\n");
    }
}