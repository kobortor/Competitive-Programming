#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, P, Q, X, Y;
char str[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> P >> Q >> X >> Y;
    cin >> str;

    deque<pii> dq;
    int sum = 0;
    for(int a = 0; a < N; a++){
        if(str[a] == '+') sum++;
        if(str[a] == '-') sum--;

        while(!dq.empty() && dq.back().second > sum){
            dq.pop_back();
        }
        dq.push_back(pii(a, sum));
    }

    int tot = sum;

    int pre = 0;
    int ans = 2e9;
    for(int a = 0; a < N; a++){
        while(!dq.empty() && dq[0].first < a){
            dq.pop_front();
        }
        assert(!dq.empty());
        int minv = dq[0].second - pre;
        int cost = (N - a) % N * Y;

        if(P + minv < 0){
            int diff = (abs(P + minv) + 1) / 2;
            cost += diff * X;
            int val = abs(Q - (P + 2 * diff + tot));
            assert(val % 2 == 0);
            cost += val / 2 * X;
        } else {
            int val = abs(Q - (P + tot));
            assert(val % 2 == 0);
            cost += val / 2 * X;
        }
        ans = min(ans, cost);

        if(str[a] == '+') sum++;
        if(str[a] == '-') sum--;

        while(!dq.empty() && dq.back().second > sum){
            dq.pop_back();
        }
        dq.push_back(pii(a + N, sum));

        if(str[a] == '+') pre++;
        if(str[a] == '-') pre--;
    }
    cout << ans;
}
