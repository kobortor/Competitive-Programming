#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
ll dp[MAXN];
ll A[MAXN];
ll B[MAXN];

double slope(int i, int j){
    assert(i < j);
    return (double)(dp[i] - dp[j]) / (B[j] - B[i]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> A[a];
    }
    for(int a = 1; a <= N; a++){
        cin >> B[a];
    }

    deque<int> dq;
    dq.push_back(1);

    dp[1] = 0;
    
    for(int a = 2; a <= N; a++){
        while((int)dq.size() >= 2){
            int i = dq[0];
            int j = dq[1];

            if(slope(i, j) <= A[a]){
                dq.pop_front();
            } else {
                break;
            }
        }

        int fr = dq[0];
        dp[a] = dp[fr] + B[fr] * A[a];

        while((int)dq.size() >= 2){
            int i = dq[dq.size() - 2];
            int j = dq[dq.size() - 1];

            if(slope(i, j) >= slope(j, a)){
                dq.pop_back();
            } else {
                break;
            }
        }
        dq.push_back(a);
    }
    cout << dp[N];
}
