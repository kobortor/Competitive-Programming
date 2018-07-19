#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A, B, N;
string str;

int cnt[13][1 << 12];
map<int, vector<pii>> ans;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> B >> N >> str;

    str.pop_back();

    for(int len = A; len <= B; len++){
        int val = 0;
        for(int a = 0; a < (int)str.size(); a++){
            val = val * 2 % (1 << len) + (str[a] - '0');
            if(a + 1 >= len){
                cnt[len][val]++;
            }
        }
    }

    for(int len = A; len <= B; len++){
        for(int a = 0; a < (1 << len); a++){
            if(cnt[len][a] == 0){
                continue;
            }

            ans[-cnt[len][a]].push_back({len, a});
        }
    }

    for(auto &au : ans){
        cout << -au.first;
        
        sort(allof(au.second));
        reverse(allof(au.second));

        for(pii p : au.second){
            cout << " " << bitset<12>(p.second).to_string().substr(12 - p.first);
        }
        cout << "\n";

        N--;
        if(N == 0){
            break;
        }
    }
}
