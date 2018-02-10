#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;
string str;

int cnt[10];

pair<int, string> solve(int targ){
    string tmp = str;
    int numSame = cnt[targ];
    int cost = 0;
    for(int diff = 1; numSame < K; diff++){
        for(int a = 0; a < N && numSame < K; a++){
            if(tmp[a] - '0' == targ + diff){
                tmp[a] = char(targ + '0');
                cost += diff;
                numSame++;
            }
        }
        for(int a = N - 1; a >= 0 && numSame < K; a--){
            if(tmp[a] - '0' == targ - diff){
                tmp[a] = char(targ + '0');
                cost += diff;
                numSame++;
            }
        }
    }
    return pair<int, string>(cost, tmp);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> str;
    for(char c : str){
        cnt[c - '0']++;
    }

    pair<int, string> best = {999999999, ""};
    for(int a = 0; a < 10; a++){
        best = min(best, solve(a));
    }
    cout << best.first << endl;
    cout << best.second;
}
