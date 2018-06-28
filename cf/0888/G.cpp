#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;

int tr[MAXN * 64][2];
vector<int> avail;

int arr[MAXN];

ll ans = 0;

int find_min(int root, int val){
    int tmp = 0;
    for(int a = 30; a >= 0; a--){
        int bit = ((val >> a) & 1);
        if(tr[root][bit] == -1){
            bit ^= 1;
            tmp |= 1 << a;
        }
        root = tr[root][bit];
    }
    return tmp;
}

void insert(int root, int val){
    for(int a = 30; a >= 0; a--){
        int bit = ((val >> a) & 1);
        if(tr[root][bit] == -1){
            tr[root][bit] = avail.back();
            avail.pop_back();
        }
        root = tr[root][bit];
    }
}

void reclaim(int root){
    if(root == -1){
        return;
    }
    reclaim(tr[root][0]);
    reclaim(tr[root][1]);

    tr[root][0] = -1;
    tr[root][1] = -1;

    avail.push_back(root);
}

int solve(const vector<int> &points, int lvl){
    if(points.empty()){
        return -1;
    }
    if((int)points.size() == 1){
        int val = points[0];
        int root = avail.back();
        avail.pop_back();
        insert(root, val);
        return root;
    }

    vector<int> nxt[2];
    for(int i : points){
        nxt[(i >> lvl) & 1].push_back(i);
    }

    int lft = solve(nxt[0], lvl - 1);
    int rht = solve(nxt[1], lvl - 1);

    if(nxt[0].empty()){
        return rht;
    }
    if(nxt[1].empty()){
        return lft;
    }

    if(nxt[0].size() < nxt[1].size()){
        int best = INT_MAX;

        for(int i : nxt[0]){
            best = min(best, find_min(rht, i));
        }

        ans += best;

        for(int i : nxt[0]){
            insert(rht, i);
        }
        reclaim(lft);
        return rht;
    } else {
        int best = INT_MAX;

        for(int i : nxt[1]){
            best = min(best, find_min(lft, i));
        }

        ans += best;

        for(int i : nxt[1]){
            insert(lft, i);
        }
        reclaim(rht);
        return lft;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(tr, -1, sizeof tr);

    vector<int> all;

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }

    //duplicates are free
    sort(arr, arr + N);
    N = unique(arr, arr + N) - arr;

    for(int a = 0; a < N; a++){
        all.push_back(arr[a]);
    }

    avail.reserve(MAXN * 64);
    for(int a = 0; a < MAXN * 64; a++){
        avail.push_back(a);
    }

    solve(all, 30);
    cout << ans;
}
