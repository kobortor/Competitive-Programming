#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

list<int> lst;

vector<list<int>::iterator> tokill;
vector<list<int>::iterator> tocheck;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;

        if(!lst.empty() && lst.back() > x){
            lst.push_back(x);
            tokill.push_back(prev(lst.end()));
        } else {
            lst.push_back(x);
        }
    }

    int ans = 0;
    while(!tokill.empty()){
        int prvcheck = -1;
        while(!tokill.empty()){
            list<int>::iterator iter = tokill.back();
            if(next(iter) != lst.end() && *next(iter) != prvcheck){
                tocheck.push_back(next(iter));
                prvcheck = *next(iter);
            }

            lst.erase(iter);
            tokill.pop_back();
        }

        tokill.clear();

        while(!tocheck.empty()){
            list<int>::iterator iter = tocheck.back();
            if(iter != lst.begin() && *prev(iter) > *iter){
                tokill.push_back(iter);
            }
            tocheck.pop_back();
        }

        ans++;
    }

    cout << ans;
}
