#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, M;
bitset<MAXN> vis[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        string str;
        cin >> str;
        vector<int> blacks;
        for(int i = 0; i < (int)str.size(); i++){
            if(str[i] == '#'){
                blacks.push_back(i);
            }
        }
        for(int i = 0; i < (int)blacks.size(); i++){
            for(int j = i + 1; j < (int)blacks.size(); j++){
                if(vis[blacks[i]][blacks[j]]){
                    cout << "no";
                    return 0;
                } else {
                    vis[blacks[i]][blacks[j]] = true;
                }
            }
        }
    }
    cout << "yes";
}
