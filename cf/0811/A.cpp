#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int candy[2];
string names[] = {"Vladik", "Valera"};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> candy[0] >> candy[1];

    int turn = 1;
    while(1){
        int player = !(turn & 1);
        if(candy[player] < turn){
            cout << names[player];
            return 0;
        } else {
            candy[player] -= turn;
            turn++;
        }
    }
}