#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
string W, S;

int getid(char ch){
    if('a' <= ch && ch <= 'z'){
        return ch - 'a';
    } else {
        return 26 + ch - 'A';
    }
}

int freq[52];
int targ[52];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> W >> S;

    int good = 52;

    for(char c : W){
        if(targ[getid(c)]++ == 0){
            good--;
        }
    }

    int ans = 0;
    
    for(int i = 0; i < (int)S.size(); i++){
        int id = getid(S[i]);
        if(++freq[id] == targ[id]){
            good++;
        }

        if(i >= (int)W.size()){
            id = getid(S[i - W.size()]);
            if(freq[id]-- == targ[id]){
                good--;
            }
        }

        if(good == 52){
            ans++;
        }
    }

    cout << ans;
}
