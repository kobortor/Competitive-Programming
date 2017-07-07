#include<bits/stdc++.h>

using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

ll N, M;
ll arr[MAXN];

vector<int> afters[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    cin >> N >> M;

    for(int a = 0; a < N; a++) {
        cin >> arr[a];
    }

    deque<pll> dq;
    dq.push_back({2e9, N});

    for(int a = N - 1; a >= 0; a--) {
        while(dq.front().first < arr[a]) {
            //cout << a << " pushed " << dq.front().second << "\n";
            afters[a].push_back(dq.front().second);
            dq.pop_front();
        }

        //cout << a << " pushed " << dq.front().second << "\n";
        afters[a].push_back(dq.front().second);

        dq.push_front({arr[a], a});
    }

    deque<pll> mindq;
    ll ans = 1;
    ll curCost = 0;
    int back = 0;

    mindq.push_back({arr[0], 0});

    for(int a = 1; a < N; a++) {
        if(arr[a] < mindq.front().first) {
            curCost += mindq.front().first - arr[a];
        } else {
            //add nothing
        }

        while(!mindq.empty() && mindq.back().first <= arr[a]) {
            mindq.pop_back();
        }

        mindq.push_back({arr[a], a});

        //cout << back << " to " << a << " costs " << curCost << "\n";

        while(curCost > M && back < a) {
            ll curPos = back;
            ll curHT = arr[back];

            for(int i : afters[back]) {
                ll xdiff = min(i, a + 1) - curPos;
                ll ydiff = arr[back] - curHT;

                curCost -= xdiff * ydiff;
                //cout << " -= " << xdiff << " * " << ydiff << "\n";
                curPos = i;
                curHT = arr[i];

                if(i > a) {
                    break;
                }
            }

            if(mindq.front().second == back) {
                mindq.pop_front();
            }

            back++;
            //cout << back << " to " << a << " costs " << curCost << "\n";
        }

        ans += a - back + 1;
    }

    cout << ans;
}
