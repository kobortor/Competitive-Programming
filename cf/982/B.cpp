#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
int wid[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> wid[a];
    }

    string str;
    cin >> str;

    priority_queue<pii> s0, s1;

    for(int a = 1; a <= N; a++){
        s0.push(pii(-wid[a], a));
    }

    for(char c : str){
        if(c == '0'){
            pii tp = s0.top();
            s0.pop();
            cout << tp.second << " ";
            s1.push(pii(-tp.first, tp.second));
        } else {
            cout << s1.top().second << " ";
            s1.pop();
        }
    }

}
