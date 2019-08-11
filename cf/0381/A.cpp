#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    deque<int> dq(n);
    for (int &i : dq) cin >> i;

    int score[2] = {0, 0};
    for (int a = 0; a < n; a++) {
        if (dq[0] > dq.back()) {
            score[a % 2] += dq[0];
            dq.pop_front();
        } else {
            score[a % 2] += dq.back();
            dq.pop_back();
        }
    }

    cout << score[0] << " " << score[1];
}
