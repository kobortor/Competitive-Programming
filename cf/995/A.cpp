#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N, K;
int grid[5][MAXN];

vector<pair<int, pii>> moves;

void park(){
    for(int a = 1; a <= N; a++){
        if(grid[1][a] != 0 && grid[1][a] == grid[2][a]){
            moves.push_back({grid[1][a], {1, a}});
            grid[1][a] = 0;
            grid[2][a] = 0;
            K--;
        }

        if(grid[4][a] != 0 && grid[3][a] == grid[4][a]){
            moves.push_back({grid[4][a], {4, a}});
            grid[3][a] = 0;
            grid[4][a] = 0;
            K--;
        }
    }
}

void print(){
    for(int a = 1; a <= 4; a++){
        for(int b = 1; b <= N; b++){
            cout << grid[a][b] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 1; a <= 4; a++){
        for(int b = 1; b <= N; b++){
            cin >> grid[a][b];
        }
    }

    park();

    if(K == 2 * N){
        cout << -1;
        return 0;
    }

    vector<pii> cycle;
    for(int a = 1; a <= N; a++){
        cycle.push_back({2, a});
    }
    for(int a = N; a >= 1; a--){
        cycle.push_back({3, a});
    }

    while(K){
        int start = 0;
        while(true){
            int nxt = (start + 1) % cycle.size();
            if(!grid[cycle[nxt].first][cycle[nxt].second]){
                break;
            } else {
                start++;
            }
        }

        for(int a = 0; a + 1 < (int)cycle.size(); a++){
            int id = (start + cycle.size() - a) % cycle.size();
            //cout << "At " << id << endl;
            int nxt = (id + 1) % cycle.size();
            //cout << cycle[id].first << "," << cycle[id].second << " -> " << cycle[nxt].first << "," << cycle[nxt].second << endl;
            if(grid[cycle[id].first][cycle[id].second]){
                //cout << "Found at " << cycle[id].first << ", " << cycle[id].second << endl;
                assert(!grid[cycle[nxt].first][cycle[nxt].second]);
                moves.push_back({grid[cycle[id].first][cycle[id].second], cycle[nxt]});
                swap(grid[cycle[id].first][cycle[id].second], grid[cycle[nxt].first][cycle[nxt].second]);

                //print();
            }
        }

        //print();
        //cout << "---\n";

        park();
    }

    cout << moves.size() << "\n";
    for(auto au : moves){
        cout << au.first << " " << au.second.first << " " << au.second.second << "\n";
    }
}
