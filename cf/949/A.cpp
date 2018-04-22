#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

string str;
bool used[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    set<int> s0, s1;

    cin >> str;
    for(int a = 0; a < (int)str.size(); a++){
        if(str[a] == '0'){
            s0.insert(a);
        } else {
            s1.insert(a);
        }
    }

    if(s0.size() <= s1.size()){
        cout << -1;
        return 0;
    }

    vector<vector<int>> ans;
    for(int a = 0; a < (int)str.size(); a++){
        if(!used[a]){
            if(str[a] == '0'){
                ans.push_back(vector<int>());

                int tp = 0;
                int idx = a;
                while(true){
                    ans.back().push_back(idx);
                    if(tp == 0){
                        auto iter = s1.upper_bound(idx);
                        if(iter != s1.end()){
                            idx = *iter;
                        } else {
                            break;
                        }
                    } else {
                        auto iter = s0.upper_bound(idx);
                        if(iter != s0.end()){
                            idx = *iter;
                        } else {
                            cout << -1;
                            return 0;
                        }
                    }
                    tp ^= 1;
                }
                for(int i : ans.back()){
                    used[i] = true;
                    if(str[i] == '0') s0.erase(i);
                    if(str[i] == '1') s1.erase(i);
                }
            } else {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for(const vector<int> &vec : ans){
        cout << vec.size();
        for(int i : vec){
            cout << " " << i + 1;
        }
        cout << "\n";
    }
}
