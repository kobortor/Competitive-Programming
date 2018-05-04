#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const unsigned MAXN = 50005;

unsigned N;
unsigned Ai[MAXN];

unsigned best[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    typedef pair<unsigned, unsigned> puu;

    cin >> N;
    for(unsigned a = 0; a < N; a++){
        cin >> Ai[a];
    }

    priority_queue<puu, vector<puu>, greater<puu>> pq;
    memset(best, 0xff, sizeof best);
    best[0] = 0;
    pq.push(puu(0, 0));
    while(!pq.empty()){
        puu top = pq.top();
        pq.pop();
        if(top.first != best[top.second]) continue;
        for(unsigned a = 1; a < N; a++){
            unsigned nxt = (top.second + Ai[a]) % Ai[0];
            unsigned cost = top.first + Ai[a];
            if(best[nxt] > cost){
                best[nxt] = cost;
                pq.push(puu(cost, nxt));
            }
        }
    }

    unsigned K;
    cin >> K;
    while(K--){
        unsigned bi;
        cin >> bi;
        if(best[bi % Ai[0]] <= bi){
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
}
