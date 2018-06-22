#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;
string str;

vector<int> letters[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> str;

    for(int a = 0; a < N; a++){
        letters[str[a] - 'a'].push_back(a);
    }

    for(int a = 0; a < 26; a++){
        int id = 0;
        while(id < (int)letters[a].size() && K){
            str[letters[a][id++]] = '!';
            K--;
        }
    }

    for(int a = 0; a < N; a++){
        if(str[a] != '!'){
            cout << str[a];
        }
    }
}
