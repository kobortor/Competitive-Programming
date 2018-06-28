#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;

string name[MAXN];
pii people[MAXN];

int N;

vector<int> ht;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> name[a];
        cin >> people[a].first;
        people[a].second = a;
    }
    sort(people, people + N);
    for(int a = 0; a < N; a++){
        if(people[a].first > (int)ht.size()){
            cout << -1;
            return 0;
        }
        ht.insert(ht.begin() + people[a].first, people[a].second);
    }
    for(int a = 0; a < N; a++){
        cout << name[people[a].second] << " " << ht.end() - find(ht.begin(), ht.end(), people[a].second) << "\n";
    }
}
