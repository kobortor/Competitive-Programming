#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, Q;
int arr[MAXN];
vector<int> pos[MAXN];
set<int> unset;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        pos[arr[a]].push_back(a);

        unset.insert(a);
    }

    if(pos[Q].empty()){
        if(pos[0].empty()){
            cout << "NO";
            return 0;
        }

        pos[Q].push_back(pos[0].back());
        arr[pos[0].back()] = Q;
    }

    for(int a = Q; a >= 1; a--){
        if(pos[a].empty()){
            continue;
        }

        int L = pos[a][0];
        int R = pos[a].back();

        for(int i : pos[a]){
            if(arr[i] != a){
                cout << "NO\n";
                return 0;
            }
        }

        auto iter = unset.lower_bound(L);
        while(iter != unset.end() && *iter <= R){
            arr[*iter] = a;
            unset.erase(iter++);
        }
    }

    cout << "YES\n";
    for(int a = 1; a <= N; a++){
        cout << max(arr[a], 1) << " ";
    }
}
