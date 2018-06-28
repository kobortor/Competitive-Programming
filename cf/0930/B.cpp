#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

string str;

int poss[26][MAXN][26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;
    for(int rot = 0; rot < (int)str.size(); rot++){
        for(int b = 1; b < (int)str.size(); b++){
            poss[str[0] - 'a'][b][str[b] - 'a']++;
        }
        rotate(str.begin(), str.begin() + 1, str.end());
    }

    int tot = 0;
    for(int a = 0; a < 26; a++){
        int most_good = 0;
        for(int b = 1; b < (int)str.size(); b++){
            int good = 0;
            for(int c = 0; c < 26; c++){
                if(poss[a][b][c] == 1){
                    good++;
                }
            }
            most_good = max(most_good, good);
        }
        tot += most_good;
    }
    cout << fixed << setprecision(15) << (double)tot / str.size();
}
