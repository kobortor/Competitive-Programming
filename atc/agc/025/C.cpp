#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int offset = 1e5 + 5;

int N;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template<class T>
using maxheap = priority_queue<T>;

vector<pii> add[MAXN * 2 + 1];
vector<pii> rem[MAXN * 2 + 1];

multiset<int> resL, resR;
multiset<int> useL, useR;

multiset<int>::iterator MAX(multiset<int> &ms){
    return prev(ms.end());
}
multiset<int>::iterator MIN(multiset<int> &ms){
    return ms.begin();
}

ll ans = 0;

void sort(){
    while(!resL.empty() && !useL.empty()){
        auto iter1 = MAX(useL);
        auto iter2 = MIN(resL);

        if(*iter1 <= *iter2){
            //ok
            break;
        } else {
            ans -= *iter2;
            ans += *iter1;

            useL.insert(*iter2);
            resL.insert(*iter1);

            useL.erase(iter1);
            resL.erase(iter2);
        }
    }

    while(!resR.empty() && !useR.empty()){
        auto iter1 = MAX(resR);
        auto iter2 = MIN(useR);

        if(*iter1 <= *iter2){
            //ok
            break;
        } else {
            ans += *iter1;
            ans -= *iter2;

            resR.insert(*iter2);
            useR.insert(*iter1);

            resR.erase(iter1);
            useR.erase(iter2);
        }
    }
}

void balance(){
    size_t minsz = min(useL.size() + resL.size(), useR.size() + resR.size());

    while(useL.size() < minsz){
        auto iter = MIN(resL);

        ans -= *iter;

        useL.insert(*iter);
        resL.erase(iter);
    }

    while(useR.size() < minsz){
        auto iter = MAX(resR);

        ans += *iter;

        useR.insert(*iter);
        resR.erase(iter);
    }

    while(useL.size() > minsz){
        auto iter = MAX(useL);

        ans += *iter;

        resL.insert(*iter);
        useL.erase(iter);
    }

    while(useR.size() < minsz){
        auto iter = MAX(useR);

        ans -= *iter;

        resR.insert(*iter);
        useR.erase(iter);
    }
}

ll best = 0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++) {
        pii p;
        cin >> p.first >> p.second;

        if(p.first > 0){
            best = max(best, 2ll * p.first);
        }
        if(p.second < 0){
            best = max(best, -2ll * p.second);
        }

        add[p.second + offset].push_back(p);
        rem[p.first + offset + 1].push_back(p);

        resR.insert(p.first);
    }

    for(ll x = 1; x < 2 * MAXN; x++){
        for(pii p : add[x]){
            resL.insert(p.second);
        }
        for(pii p : rem[x]){
            auto iter = resR.find(p.first);
            if(iter == resR.end()){
                ans -= p.first;
                useR.erase(useR.find(p.first));
            } else {
                resR.erase(iter);
            }
        }

        sort();
        balance();

        //start on left
        if(!useL.empty() && *MAX(useL) <= 0){
            ll tmp = 2 * ans;

            if(!resL.empty()){
                tmp += 2 * -*MIN(resL);
            }
            best = max(best, tmp);
        }

        //start on right
        if(!useL.empty() && *MIN(useR) >= 0){
            ll tmp = 2 * ans;

            if(!resR.empty()){
                tmp += 2 * *MAX(resR);
            }

            best = max(best, tmp);
        }
    }
    cout << best;
}
