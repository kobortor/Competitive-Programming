#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

vector<int> elem[MAXN];
int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for(int a = 1; a <= N; a++) {
        int x;
        cin >> x;
        elem[x].push_back(a);
        if((int)elem[x].size() > K){
            cout << "NO";
            return 0;
        }
    }

    int idx = 0;
    for(int a = 1; a <= 5000; a++){
        for(int i = 0; i < (int)elem[a].size(); i++, idx = (idx + 1) % K){
            ans[elem[a][i]] = idx;
        }
    }

    cout << "YES\n";
    for(int a = 1; a <= N; a++){
        cout << ans[a] + 1 << " ";
    }
}
