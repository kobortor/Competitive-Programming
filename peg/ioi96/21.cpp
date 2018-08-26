#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
int arr[MAXN];
int targ[MAXN];
vector<int> bucket[4][4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        targ[a] = arr[a];
    }
    sort(targ + 1, targ + N + 1);

    for(int a = 1; a <= N; a++){
        if(arr[a] != targ[a]){
            bucket[arr[a]][targ[a]].push_back(a);
        }
    }

    vector<pii> ans;

    for(int a = 1; a <= 3; a++){
        for(int b = a + 1; b <= 3; b++){
            while(!bucket[a][b].empty() && !bucket[b][a].empty()){
                int p = bucket[a][b].back();
                int q = bucket[b][a].back();

                bucket[a][b].pop_back();
                bucket[b][a].pop_back();

                ans.push_back({p, q});
            }
        }
    }

    while(!bucket[1][2].empty()){
        int p = bucket[1][2].back();
        int q = bucket[2][3].back();
        int r = bucket[3][1].back();

        bucket[1][2].pop_back();
        bucket[2][3].pop_back();
        bucket[3][1].pop_back();

        ans.push_back({q, r});
        ans.push_back({p, r});
    }

    while(!bucket[2][1].empty()){
        int p = bucket[1][3].back();
        int q = bucket[3][2].back();
        int r = bucket[2][1].back();

        bucket[1][3].pop_back();
        bucket[3][2].pop_back();
        bucket[2][1].pop_back();

        ans.push_back({q, r});
        ans.push_back({p, r});
    }

    cout << ans.size() << "\n";
    for(pii p : ans){
        cout << p.first << " " << p.second << "\n";
    }
}
