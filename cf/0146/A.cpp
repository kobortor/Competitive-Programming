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

    for(char c : str){
        if(c != '4' && c != '7'){
            cout << "NO";
            return 0;
        }
    }

    int ans = 0;
    for(int a = 0; a < N / 2; a++){
        ans += str[a] - str[a + N / 2];
    }
    cout << (ans == 0 ? "YES" : "NO");
}
