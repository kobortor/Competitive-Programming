#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, M;
pii cat[MAXN];
int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> cat[a].first >> cat[a].second;
    }

    for(int a = 0; a < M; a++){
        pii dog;
        cin >> dog.first >> dog.second;

        int best_dist = 1e9;
        int best = -1;
        for(int b = 0; b < N; b++){
            int dist = (dog.first - cat[b].first) * (dog.first - cat[b].first) + (dog.second - cat[b].second) * (dog.second - cat[b].second);
            if(dist < best_dist){
                best_dist = dist;
                best = b;
            }
        }
        cnt[best]++;
    }
    cout << count(cnt, cnt + N, 1);
}
