#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXH = 1e5 + 5;

int H;
int cnt[MAXH];

void solve1(){
    int par = 0, tmp = 0;
    int id = 1;

    for(int a = 0; a <= H; a++){
        for(int b = 0; b < cnt[a]; b++){
            cout << par << " ";

            tmp = id;
            id++;
        }
        par = tmp;
    }
    cout << "\n";
}

void solve2(){
    vector<int> par{0}, tmp;
    int id = 1;

    for(int a = 0; a <= H; a++){
        for(int b = 0; b < cnt[a]; b++){
            cout << par[b % par.size()] << " ";

            tmp.push_back(id);
            id++;
        }
        par = tmp;
        tmp.clear();
    }
    cout << "\n";
}

void solve_dup(){
    cout << "ambiguous\n";
    solve1();
    solve2();
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> H;
    for(int a = 0; a <= H; a++){
        cin >> cnt[a];
    }

    for(int a = 1; a <= H; a++) {
        if(cnt[a] > 1 && cnt[a - 1] > 1){
            solve_dup();
            return 0;
        }
    }
    cout << "perfect\n";
}