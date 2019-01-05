#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;

vector<string> flip(vector<string> grid){
    vector<string> out;
    for(int b = 0; b < (int)grid[0].size(); b++){
        out.emplace_back();
        for(int a = 0; a < (int)grid.size(); a++){
            out.back() += grid[a][b];
        }
    }
    return out;
}

pair<int, vector<string>> check(vector<string> grid, char c11, char c12, char c21, char c22){
    vector<string> out;
    vector<char> v[2] = {{c11, c12}, {c21, c22}};
    int ans = 0;
    for(int a = 0; a < (int)grid.size(); a++){
        int cnt = 0, flipcnt = 0;
        for(int b = 0; b < (int)grid[0].size(); b++){
            cnt += (grid[a][b] != v[a % 2][b % 2]);
            flipcnt += (grid[a][b] != v[a % 2][(b + 1) % 2]);
        }

        out.emplace_back();
        if(cnt < flipcnt){
            for(int b = 0; b < (int)grid[0].size(); b++){
                out.back() += v[a % 2][b % 2];
            }
            ans += cnt;
        } else {
            for(int b = 0; b < (int)grid[0].size(); b++){
                out.back() += v[a % 2][(b + 1) % 2];
            }
            ans += flipcnt;
        }
    }

    return {ans, out};
}

pair<int, vector<string>> solve(vector<string> grid){
    vector<char> v = {'A', 'G', 'C', 'T'};
    sort(allof(v));

    int ans = 4e5;
    vector<string> best;
    do {
        int val;
        vector<string> gr;
        tie(val, gr) = check(grid, v[0], v[1], v[2], v[3]);
        if(val < ans){
            ans = val;
            best = gr;
        }
    } while (next_permutation(allof(v)));

    return {ans, best};
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    vector<string> grid, grid2;
    for(int a = 0; a < N; a++){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    grid2 = flip(grid);

    auto ans1 = solve(grid);
    auto ans2 = solve(grid2);

    if(ans1.first < ans2.first){
        for(string s : ans1.second){
            cout << s << endl;
        }
    } else {
        ans2.second = flip(ans2.second);
        for(string s : ans2.second){
            cout << s << endl;
        }
    }
}
