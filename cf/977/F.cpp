#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
unordered_map<int, int> ump;
int len[MAXN];
int prv[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;

        auto iter = ump.find(x-1);
        if(iter == ump.end()){
            prv[a] = -1;
            len[a] = 1;
        } else {
            prv[a] = iter->second;
            len[a] = len[prv[a]] + 1;
        }

        ump[x] = a;
    }

    int best = max_element(len + 1, len + N + 1) - len;

    vector<int> vec;
    while(best != -1){
        vec.push_back(best);
        best = prv[best];
    }
    reverse(allof(vec));

    cout << vec.size() << "\n";
    for(int i : vec){
        cout << i << " ";
    }
}
