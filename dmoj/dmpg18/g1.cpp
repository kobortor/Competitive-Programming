#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, K;
int idx[MAXN];
bitset<MAXN> empty, stu;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 0; a < K; a++){
        int x;
        cin >> x;
        empty[x] = true;
    }
    
    for(int a = 0; a < K + 1; a++){
        int x;
        cin >> x;
        idx[x] = a + 1;
        stu[x] = true;
    }

    vector<int> stk;
    for(int a = N; a >= 1; a--){
        if(empty[a]){
            stk.push_back(a);
        }
        if(stu[a]){
            if(!stk.empty()){
                stu[a] = false;
                stk.pop_back();
            }
        }
    }

    for(int a = N; a >= 1; a--){
        if(stu[a]){
            if(!stk.empty()){
                stu[a] = false;
                stk.pop_back();
            }
        }       
    }

    assert(stk.empty());
    for(int a = 1; a <= N; a++){
        if(stu[a]){
            cout << idx[a];
            return 0;
        }
    }
}
