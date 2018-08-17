#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, K;
string S;

bool use[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    cin >> S;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int a = 0; a < N; a++){
        if(S[a] == ')'){
            pq.push(a);
        }
    }

    for(int a = 0; a < N && K; a++){
        while(!pq.empty() && pq.top() <= a){
            pq.pop();
        }
        if(S[a] == '('){
            if(!pq.empty()){
                use[a] = true;
                use[pq.top()] = true;
                pq.pop();
                K -= 2;
            }
        }
    }

    for(int a = 0; a < N; a++){
        if(use[a]){
            cout << S[a];
        }
    }
}
