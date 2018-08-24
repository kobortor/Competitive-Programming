#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e6 + 6;

int N;
vector<int> uniq;
int add[MAXN], sub[MAXN];
int N0[MAXN], N1[MAXN];
pii seg[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> seg[a].first >> seg[a].second;
        uniq.push_back(seg[a].first - 1);
        uniq.push_back(seg[a].first);
        uniq.push_back(seg[a].first + 1);

        uniq.push_back(seg[a].second - 1);
        uniq.push_back(seg[a].second);
        uniq.push_back(seg[a].second + 1);
    }

    uniq.push_back(-1);
    uniq.push_back(2e9);
    sort(allof(uniq));
    uniq.erase(unique(allof(uniq)), uniq.end());

    for(int a = 1; a <= N; a++){
        seg[a].first = lower_bound(allof(uniq), seg[a].first) - uniq.begin();
        seg[a].second = lower_bound(allof(uniq), seg[a].second) - uniq.begin();
        add[seg[a].first]++;
        sub[seg[a].second]++;
    }

    for(int a = 1, cur = 0; a < (int)uniq.size(); a++){
        N0[a] = N0[a - 1];
        N1[a] = N1[a - 1];
        if(cur == N - 1){
            N1[a] += uniq[a] - uniq[a - 1];
        } else if (cur == N){
            N0[a] += uniq[a] - uniq[a - 1];
        }

        cur += add[a];
        cur -= sub[a];
    }

    int ans = 0;
    for(int a = 1; a <= N; a++){
        int l = seg[a].first;
        int r = seg[a].second;

        ans = max(ans, N1[l] + (N1[(int)uniq.size() - 1] - N1[r]) + (N0[r] - N0[l]));
    }

    cout << ans;
}
