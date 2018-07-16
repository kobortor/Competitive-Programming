#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;
int photos[MAXN];
vector<int> ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    if(N == 3 && M < 3){
        cout << -1;
        return 0;
    }

    int tot = 0;
    for(int a = 1; a <= M; a++){
        cin >> photos[a];
        tot += photos[a];
    }

    int mx = max_element(photos + 1, photos + M + 1) - photos;
    int mxv = min(photos[mx], N / 2);

    if(tot - photos[mx] < mxv || tot < N){
        cout << -1;
        return 0;
    }

    int cnt = 0;
    bool cycled = false;
    for(int a = 1; cnt < N; a++){
        if(!cycled){
            ans[a].push_back(mx);
            cnt++;
        }

        bool added = false;
        for(int b = 1; b <= M; b++){
            if(ans[a].back() != b && b != mx && photos[b]){
                added = true;
                photos[b]--;
                ans[a].push_back(b);
                cnt++;
                break;
            }
        }

        if(!added){
            break;
        }

        if(a == mxv){
            a = 0;
            cycled = true;
        }
    }

    if(cnt >= N){
        for(int a = 1; a <= mxv; a++){
            for(int i : ans[a]){
                cout << i << " ";
            }
        }
    } else {
        cout << -1;
    }
}
