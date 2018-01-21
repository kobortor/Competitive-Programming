#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXK = 4005;

int N, K;

int prefix[MAXK][MAXK];

void add_rect(int r1, int c1, int r2, int c2, int val){
    r1 += K;
    r2 += K;
    c1 += K;
    c2 += K;
    assert(0 <= r1);
    assert(0 <= r2);
    assert(0 <= c1);
    assert(0 <= c2);
    prefix[r1][c1] += val;
    prefix[r2 + 1][c1] -= val;
    prefix[r1][c2 + 1] -= val;
    prefix[r2 + 1][c2 + 1] += val;
}

int ans[MAXK][MAXK];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> K;
    for(int a = 0; a < N; a++){
        int R, C;
        char ch;
        cin >> C >> R >> ch;

        C %= 2 * K;
        R %= 2 * K;

        if(ch == 'W'){
            add_rect(R - K + 1, C - K + 1, R, C, 1);
            add_rect(R + 1, C + 1, R + K, C + K, 1);
        } else {
            prefix[0][0]++;
            prefix[2 * K][0]--;
            prefix[0][2 * K]--;
            prefix[2 * K][2 * K]++;
            add_rect(R - K + 1, C - K + 1, R, C, -1);
            add_rect(R + 1, C + 1, R + K, C + K, -1);
        }
    }
    for(int a = 1; a < MAXK; a++){
        for(int b = 0; b < MAXK; b++){
            prefix[a][b] += prefix[a - 1][b];
        }
    }
    for(int a = 0; a < MAXK; a++){
        for(int b = 1; b < MAXK; b++){
            prefix[a][b] += prefix[a][b - 1];
        }
    }
    for(int a = 0; a < MAXK; a++){
        for(int b = 0; b < MAXK; b++){
            ans[a % (2 * K)][b % (2 * K)] += prefix[a][b];
        }
    } 
    int best = 0;
    for(int a = 0; a < 2 * K; a++){
        for(int b = 0; b < 2 * K; b++){
            //cout << ans[a][b] << " ";
            best = max(best, ans[a][b]);
        }
        //cout << endl;
    }
    cout << best;
}
