#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXT = 1e6 + 6;

int A, B, T, *X, *Y, *W, *S;
pii toys[MAXT];

bool check(int tm){
    priority_queue<int> pq;

    int idx = 0;
    for(int a = 0; a < A; a++){
        while(idx < T && toys[idx].first < X[a]){
            pq.push(toys[idx++].second);
        }
        for(int b = 0; b < tm && !pq.empty(); b++){
            pq.pop();
        }
    }

    while(idx < T){
        pq.push(toys[idx++].second);
    }

    for(int a = B - 1; a >= 0; a--){
        for(int b = 0; b < tm && !pq.empty() && pq.top() < Y[a]; b++){
            pq.pop();
        }
    }

    return pq.empty();
}

int putaway(int _A, int _B, int _T, int _X[], int _Y[], int _W[], int _S[]){
    A = _A;
    B = _B;
    T = _T;
    X = _X;
    Y = _Y;
    W = _W;
    S = _S;

    sort(X, X + A);
    sort(Y, Y + B);

    for(int a = 0; a < T; a++){
        toys[a] = {W[a], S[a]};
        if(W[a] >= X[A - 1] && S[a] >= Y[B - 1]){
            return -1;
        }
    }

    sort(toys, toys + T);

    int lo = 1, hi = T;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}
