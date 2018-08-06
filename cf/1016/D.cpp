#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, M;
int row[MAXN], col[MAXN];
int ans[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> row[a];
    }

    for(int a = 0; a < M; a++){
        cin >> col[a];
    }

    for(int i = 0; i < 30; i++){
        vector<int> R, C;
        for(int a = 0; a < N; a++){
            if(row[a] & (1 << i)){
                R.push_back(a);
            }
        }
        for(int a = 0; a < M; a++){
            if(col[a] & (1 << i)){
                C.push_back(a);
            }
        }
        if(R.size() % 2 != C.size() % 2){
            cout << "NO\n";
            return 0;
        }

        while(C.size() < R.size()){
            C.push_back(0);
        }
        while(R.size() < C.size()){
            R.push_back(0);
        }

        for(int a = 0; a < (int)R.size(); a++){
            ans[R[a]][C[a]] ^= 1 << i;
        }
    }

    cout << "YES\n";
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cout << ans[a][b] << " ";
        }
        cout << "\n";
    }
}
