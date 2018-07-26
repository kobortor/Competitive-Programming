#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;
const int ARRSZ = MAXN * 25;

int tcnt = 1;
struct node {
    int l, r;
    int lnode, rnode, sum;
} tr[ARRSZ];

int root[MAXN];

int N;

vector<pii> K;
vector<int> qlist;
vector<vector<int>> gaps;
vector<int> dp;

int build(int l, int r){
    int nt = tcnt++;
    tr[nt].l = l;
    tr[nt].r = r;
    if(l != r){
        int mid = (l + r) / 2;
        tr[nt].lnode = build(l, mid);
        tr[nt].rnode = build(mid + 1, r);
        tr[nt].sum = tr[tr[nt].lnode].sum + tr[tr[nt].rnode].sum;
    }
    return nt;
}

int insert(int loc, int pos){
    int nt = tcnt++;
    tr[nt] = tr[pos];

    if(tr[nt].l == tr[nt].r){
        tr[nt].sum++;
    } else {
        int mid = tr[tr[nt].lnode].r;
        if(loc <= mid){
            tr[nt].lnode = insert(loc, tr[nt].lnode);
        } else {
            tr[nt].rnode = insert(loc, tr[nt].rnode);
        }
        tr[nt].sum = tr[tr[nt].lnode].sum + tr[tr[nt].rnode].sum;
    }
    return nt;
}

int lvl, qidx;
void query(int sum, int pos){
    if(tr[pos].l == tr[pos].r){
        gaps[lvl][qidx--] = sum + tr[pos].sum;
        return;
    }

    int mid = tr[tr[pos].lnode].r;

    if(qidx >= lvl && qlist[qidx] > mid){
        query(sum, tr[pos].rnode);
    }

    sum += tr[tr[pos].rnode].sum;
    if(qidx >= lvl && qlist[qidx] >= tr[pos].l){
        query(sum, tr[pos].lnode);
    }
}

void init(int _N, int _A[], int _B[]){
    N = _N;

    vector<pii> stu(N);
    for(int a = 0; a < N; a++){
        stu[a] = {_A[a], _B[a]};
    }

    sort(allof(stu));

    root[0] = build(0, N);
    
    int idx = 0;
    for(int a = 1; a <= N; a++){
        root[a] = root[a - 1];
        while(idx < N && stu[idx].first <= a){
            root[a] = insert(stu[idx].second, root[a]);
            idx++;
        }
    }

    int sq = sqrt(2 * N) + 2;

    gaps = vector<vector<int>>(sq, vector<int>(sq));
    dp = vector<int>(sq);
}

int can(int M, int *_K){
    int sum = 0;
    for(int a = 0; a < M; a++){
        sum += _K[a];
        if(sum > N){
            return false;
        }
    }

    sort(_K, _K + M);

    K.clear();
    qlist.clear();

    K.emplace_back(0, 0);
    qlist.emplace_back(0);

    int cur = 0;
    while(cur < M){
        int nxt = cur + 1;
        while(nxt < M && _K[nxt] == _K[cur]){
            nxt++;
        }
        K.emplace_back(_K[cur], nxt - cur);
        qlist.emplace_back(_K[cur]);
        cur = nxt;
    }

    for(lvl = 1; lvl < (int)K.size(); lvl++){
        qidx = K.size() - 1;
        query(0, root[K[lvl].first]);
    }

    for(int a = 1; a < (int)K.size(); a++){
        int best = 9999999;
        for(int b = 0; b < a; b++){
            best = min(best, dp[b] + (gaps[a][a] - gaps[b][a]) - K[a].first * K[a].second);
        }

        if(best < 0){
            return false;
            break;
        }
        dp[a] = best;
    }

    return true;
}
