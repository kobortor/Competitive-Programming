#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int W, H;

char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

pair<pii, pii> dfs(int r, int c){
    vis[r][c] = true;

    pair<pii, pii> ans = {pii(r, r), pii(c, c)};
    
    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            if(!vis[r + a][c + b] && grid[r + a][c + b] == '1'){
                pair<pii, pii> rect = dfs(r + a, c + b);

                ans.first.first = min(ans.first.first, rect.first.first);
                ans.first.second = max(ans.first.second, rect.first.second);

                ans.second.first = min(ans.second.first, rect.second.first);
                ans.second.second = max(ans.second.second, rect.second.second);
            }
        }
    }

    return ans;
}

void unset_dfs(int r, int c, char ch){
    vis[r][c] = false;
    grid[r][c] = ch;
    
    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            if(vis[r + a][c + b] && grid[r + a][c + b] == '1'){
                unset_dfs(r + a, c + b, ch);
            }
        }
    }
}

void rot90(vector<string> &vec){
    vector<string> newvec;
    int wid = vec[0].size();

    for(int b = wid - 1; b >= 0; b--){
        newvec.emplace_back();
        for(int a = 0; a < (int)vec.size(); a++){
            newvec.back() += vec[a][b];
        }
    }

    vec.swap(newvec);
}

unordered_map<string, char> ump;

int getid(const string &str){
    return ump.emplace(str, 'a' + ump.size()).first->second;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> W >> H;
    for(int a = 1; a <= H; a++){
        cin >> (grid[a] + 1);
    }

    for(int a = 1; a <= H; a++){
        for(int b = 1; b <= W; b++){
            if(grid[a][b] == '1'){
                pair<pii, pii> rect = dfs(a, b);

                vector<string> vec;
                for(int r = rect.first.first; r <= rect.first.second; r++){
                    vec.emplace_back();
                    for(int c = rect.second.first; c <= rect.second.second; c++){
                        vec.back().push_back('0' + vis[r][c]);
                    }
                }

                string best = "999";

                for(int i = 0; i < 4; i++){
                    string tmp;
                    for(string str : vec){
                        tmp += str;
                        tmp += "!";
                    }
                    best = min(best, tmp);
                    rot90(vec);
                }

                for(string &str : vec){
                    reverse(allof(str));
                }

                for(int i = 0; i < 4; i++){
                    string tmp;
                    for(string str : vec){
                        tmp += str;
                        tmp += "!";
                    }
                    best = min(best, tmp);
                    rot90(vec);
                }

                unset_dfs(a, b, getid(best));
            }
        }
    }

    for(int a = 1; a <= H; a++){
        cout << (grid[a] + 1) << "\n";
    }
}
