#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool vis[26];

string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;

    if(str.size() < 26){
        for(int a = 0; a < (int)str.size(); a++){
            int ch = str[a] - 'a';
            vis[ch] = true;
        }
        for(int a = 0; a < 26; a++){
            if(!vis[a]){
                str += char(a + 'a');
                cout << str;
                return 0;
            }
        }
    }

    string bad = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    string best = bad;
    for(int a = 0; a < (int)str.size(); a++){
        int ch = str[a] - 'a';

        string tmp = str.substr(0, a);
        bool good = false;
        for(int b = ch + 1; b < 26; b++){
            if(!vis[b]){
                tmp += char(b + 'a');
                good = true;
                break;
            }
        }
        if(good){
            best = min(best, tmp);
        }

        if(vis[ch]){
            break;
        } else {
            vis[ch] = true;
        }
    }

    if(best == bad){
        cout << -1;
    } else {
        cout << best;
    }
}
