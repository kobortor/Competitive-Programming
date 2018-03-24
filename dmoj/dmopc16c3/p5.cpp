#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 7;

int N, K;
vector<unsigned> best[MAXN];
unsigned arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    best[2].push_back(0);

    for(int a = 3; a < N + 3; a++){
        cin >> arr[a];
        arr[a] *= 2;

        size_t id1 = 0, id2 = 0, id3 = 0;

        unsigned cost1 = arr[a];
        unsigned cost2 = arr[a] + arr[a - 1] - min(arr[a], arr[a - 1]) / 2;
        unsigned cost3 = arr[a] + arr[a - 1] + arr[a - 2] - min(arr[a], min(arr[a - 1], arr[a - 2]));

        best[a].reserve(min(K, (int)best[a - 1].size() + (int)best[a - 2].size() + (int)best[a - 3].size()));
        
        while((int)best[a].size() < K && (id1 < best[a - 1].size() || id2 < best[a - 2].size() || id3 < best[a - 3].size())){
            unsigned best1 = id1 < best[a - 1].size() ? best[a - 1][id1] + cost1 : 0xFFFFFFFFu;
            unsigned best2 = id2 < best[a - 2].size() ? best[a - 2][id2] + cost2 : 0xFFFFFFFFu;
            unsigned best3 = id3 < best[a - 3].size() ? best[a - 3][id3] + cost3 : 0xFFFFFFFFu;

            if (best1 <= best2 && best1 <= best3) {
                best[a].push_back(best1);
                id1++;
            } else if (best2 <= best1 && best2 <= best3) {
                best[a].push_back(best2);
                id2++;
            } else if (best3 <= best1 && best3 <= best2) { 
                best[a].push_back(best3);
                id3++;
            }
            if((int)best[a].size() >= 2){
                unsigned back = best[a].back();
                best[a].pop_back();
                if(back != best[a].back()){
                    best[a].push_back(back);
                }
            }
        }

        best[a - 3].clear();
        best[a - 3].shrink_to_fit();

        while((int)best[a].size() > K){
            best[a].pop_back();
        }
    }

    if((int)best[N + 2].size() < K){
        cout << -1;
    } else {
        cout << fixed << setprecision(1) << best[N + 2].back() / 2.0;
    }
}
