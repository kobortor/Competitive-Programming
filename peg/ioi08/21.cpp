#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, M;
string str;

int numL = 0, numP = 0;

//[numL][numP - numL + 2][prv type]
//LL - 0
//PP - 1
//Neither
int dp[MAXN][5][2];



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    cin >> str;

    for(char c : str){
        if(c == 'L'){
            numL++;
        } else {
            numP++;
        }
    }
}
