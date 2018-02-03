#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool seenR[36][36];
bool seenC[36][36];

string sq[36];

int val(char ch){
    if(isdigit(ch)){
        return ch - '0';
    } else {
        return ch - 'A' + 10;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int a = 0; a < N; a++){
        cin >> sq[a];
        for(int b = 0; b < N; b++){
            seenR[a][val(sq[a][b])] = true;
            seenC[b][val(sq[a][b])] = true;
        }
    }
    for(int a = 0; a < N; a++){
        int cntR = 0, cntC = 0;
        for(int b = 0; b < N; b++){
            if(seenR[a][b]){
                cntR++;
            }
            if(seenC[a][b]){
                cntC++;
            }
        }
        if(cntR != N || cntC != N){
            cout << "No";
            return 0;
        }
    }
    bool reduced = true;
    for(int a = 1; a < N; a++){
        reduced &= val(sq[0][a]) > val(sq[0][a - 1]);
        reduced &= val(sq[a][0]) > val(sq[a - 1][0]);
    }
    cout << (reduced ? "Reduced" : "Latin");
}
