#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;

int N, M;
vector<int> voters[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);


    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        int vote, cost;
        cin >> vote >> cost;
        voters[vote].push_back(cost);
    }

    for(int a = 1; a <= M; a++){
        sort(allof(voters[a]));
    }

    ll ans = 1e18;
    for(int thresh = 1; thresh <= N; thresh++){
        int num1 = voters[1].size();
        ll cost = 0;
        vector<int> remain;

        for(int a = 2; a <= M; a++){
            int prvsz = remain.size();
            if((int)voters[a].size() < thresh){
                remain.insert(remain.end(), allof(voters[a]));
            } else {
                num1 += voters[a].size() - (thresh - 1);
                for(int b = 0; b + thresh - 1 < (int)voters[a].size(); b++){
                    cost += voters[a][b];
                }

                remain.insert(remain.end(), voters[a].end() - (thresh - 1), voters[a].end());
            }
        }

        sort(allof(remain));
        reverse(allof(remain));
        
        while(num1 < thresh){
            num1++;
            cost += remain.back();
            remain.pop_back();
        }

        ans = min(ans, cost);
    }

    cout << ans;
}
