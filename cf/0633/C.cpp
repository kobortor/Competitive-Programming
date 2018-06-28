#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXM = 1e5 + 5;
const int MAXN = 1e6 + 6;

int cnt = 0;
struct node {
    int word;
    int child[26];
}tr[MAXN];

int prv[MAXN];
string words[MAXM];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(tr, -1, sizeof tr);
    memset(prv, -1, sizeof prv);

    int N;
    string str;
    cin >> N >> str;

    int M;
    cin >> M;
    for(int a = 0; a < M; a++){
        cin >> words[a];

        int cur = 0;
        for(int i = words[a].size() - 1; i >= 0; i--){
            int ch = tolower(words[a][i]) - 'a';
            if(tr[cur].child[ch] == -1){
                tr[cur].child[ch] = ++cnt;
            }
            cur = tr[cur].child[ch];
        }
        tr[cur].word = a;
    }

    prv[0] = 0;
    for(int a = 0; a < (int)str.size(); a++){
        int cur = 0;
        for(int b = a; b < (int)str.size(); b++){
            int ch = str[b] - 'a';
            if(tr[cur].child[ch] == -1){
                break;
            }
            cur = tr[cur].child[ch];
            if(tr[cur].word != -1 && prv[a] != -1){
                prv[b + 1] = tr[cur].word;
            }
        }
    }
    vector<int> out;
    int idx = str.size();
    while(idx){
        out.push_back(prv[idx]);
        idx -= words[prv[idx]].size();
    }
    while(!out.empty()){
        cout << words[out.back()] << " ";
        out.pop_back();
    }
}
