#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, S;

ll get_min_branch(){
    ll lo = 1, hi = N - 1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        ll rem = N, avail = 1, min_sum = 0;
        for(int a = 1; rem; a++, avail *= mid){
            ll diff = min(rem, avail);
            min_sum += diff * a;
            rem -= diff;
        }

        if(min_sum <= S){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}

ll level[MAXN];
vector<int> nodes[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;

    ll max_sum = N * (N + 1) / 2;

    if(max_sum < S || S < 1 + (N - 1) * 2){
        cout << "No";
        return 0;
    }

    ll branch = get_min_branch();

    cout << "Yes" << endl;
    if(branch == 1){
        for(int a = 2; a <= N; a++){
            cout << a - 1 << " ";
        }
    } else {
        ll sum = N * (N + 1) / 2;
        for(int a = 1; a <= N; a++){
            level[a] = 1;
        }
        int layer = 2;
        for(int a = N; a > layer && sum != S; a--){
            while(level[layer] == level[layer - 1] * branch){
                layer++;
            }
            while(sum - a + layer < S){
                layer++;
            }

            level[layer]++;
            level[a]--;
            sum -= a;
            sum += layer;
        }

        int id = 1;
        for(int a = 1; a <= N; a++){
            while(level[a]--){
                nodes[a].push_back(id++);
            }
        }

        for(int a = 2; a <= N; a++){
            int pos = 0;
            for(int b = 0; b < (int)nodes[a].size(); b++){
                //cout << nodes[a][b] << " -> " << nodes[a - 1][pos] << endl;
                cout << nodes[a - 1][pos] << " ";
                if(b % branch == branch - 1){
                    pos++;
                }
            }
        }
    }
}
