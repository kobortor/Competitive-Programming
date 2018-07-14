#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> str;

    int numW = 0, numE = 0;
    for(int a = 0; a < N; a++){
        numE += str[a] == 'E';
    }

    int best = 1e9;
    for(int a = 0; a < N; a++){
        numE -= str[a] == 'E';

        best = min(best, numE + numW);

        numW += str[a] == 'W';
    }

    cout << best;
}
