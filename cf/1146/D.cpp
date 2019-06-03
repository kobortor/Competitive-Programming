#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

ll lim;
ll M, A, B;
ll cur = 1, ans = 0;
bool vis[MAXN];

ll gcd (ll a, ll b){ 
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

// (0/g+1 + 1/g+1 + 2/g+1 + 3/g+1 + ... + N/g+1) (all round down)
ll gsum(ll N, ll g) {
    ll ans = N + 1;
    ans += (N % g + 1) * (N / g);

    N = N / g * g - 1;

    ll steps = N / g;
    ans += g * (steps * (steps + 1) / 2);
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M >> A >> B;
    vis[0] = true;

    lim = 0;
    while (lim < MAXN && lim <= M) {
        if (lim - A >= 0 && vis[lim - A]) {
            queue<int> q;
            q.push(lim);
            vis[lim] = true;

            while (!q.empty()) {
                cur++;
                int fr = q.front();
                q.pop();

                if (fr + A <= lim && !vis[fr + A]) {
                    q.push(fr + A);
                    vis[fr + A] = true;
                }
                if (fr - B >= 0 && !vis[fr - B]) {
                    q.push(fr - B);
                    vis[fr - B] = true;
                }
            }
        }

        lim++;
        ans += cur;
    }

    if (M >= MAXN) {
        ll g = gcd(A, B);
        ans += gsum(M, g) - gsum(MAXN - 1, g);
    }

    cout << ans;
}
