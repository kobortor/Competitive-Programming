#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii sq[2][4];

set<int> bound1[2];
set<int> bound2[2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < 2; a++){
        for(int b = 0; b < 4; b++){
            cin >> sq[a][b].first;
            cin >> sq[a][b].second;
        }
    }

    if(sq[0][0].first == sq[0][1].first || sq[0][0].second == sq[0][1].second){
        //good
    } else {
        for(int a = 0; a < 4; a++){
            swap(sq[0][a], sq[1][a]);
        }
    }

    for(int a = 0; a < 4; a++){
        bound1[0].insert(sq[0][a].first);
        bound1[1].insert(sq[0][a].second);
    }

    for(int a = 0; a < 4; a++){
        bound2[0].insert(sq[1][a].second - sq[1][a].first); //increasing
        bound2[1].insert(sq[1][a].second + sq[1][a].first); //decreasing
    }

    for(int x = -100; x <= 100; x++){
        for(int y = -100; y <= 100; y++){
            bool good = true;
            good &= *bound1[0].begin() <= x && x <= *prev(bound1[0].end());
            good &= *bound1[1].begin() <= y && y <= *prev(bound1[1].end());

            int v0 = y - x;
            int v1 = y + x;
            good &= *bound2[0].begin() <= v0 && v0 <= *prev(bound2[0].end());
            good &= *bound2[1].begin() <= v1 && v1 <= *prev(bound2[1].end());

            if(good){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}
