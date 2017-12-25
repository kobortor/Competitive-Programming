#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

#define allof(x) x.begin(), x.end()

int N;
int arr[MAXN];

priority_queue<pii> pq;
int base = 0;
int chng[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pq.push({-1, -1});
    pq.push({-1, -1});

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];

        if(pq.top().first < arr[a]){
            //always good
            chng[a]--;
            base++;
        } else {
            pii tmp = pq.top();
            pq.pop();
            if(pq.top().first < arr[a]){
                //would be good if the first one is removed
                chng[tmp.second]++;
            } else {
                //would never be good
            }
            pq.push(tmp);
        }

        pq.push({arr[a], a});
    }

    cout << base + *max_element(chng, chng + N);
}