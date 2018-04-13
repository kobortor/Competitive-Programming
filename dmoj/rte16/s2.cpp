#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2505;

string str;

pii dir[4] = {{0,1},{0,-1},{-1,0},{1,0}};
string dstr[4];

set<pii> avail[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < 4; a++){
        cin >> dstr[a];
    }
    cin >> str;

    avail[0].insert(pii(0,0));
    for(int a = 0; a < (int)str.size(); a++){
        for(int b = 0; b < 4; b++){
            if(a + dstr[b].size() <= str.size()){
                if(str.substr(a, dstr[b].size()) == dstr[b]){
                    for(pii p : avail[a]){
                        pii np = pii(p.first + dir[b].first, p.second + dir[b].second);
                        avail[a + dstr[b].size()].insert(np);
                    }
                }
            }
        }
    }
    cout << avail[str.size()].size();
}
