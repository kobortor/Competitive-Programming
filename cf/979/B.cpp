#include<bits/stdc++.h>
using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string A, B, C;

int best(string &str){
    map<char, int> mp;
    mp['!'] = 0;
    for(char c : str){
        mp[c]++;
    }
    int best = 0;
    for(auto au : mp){
        int tmp = min((int)str.size(), au.second + N);
        if(N == 1 && tmp == (int)str.size() && (au.second + N) % 2 != (int)str.size() % 2){
            tmp--;
        }
        best = max(best, tmp);
    }
    return best;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B >> C;
    int SA = best(A);
    int SB = best(B);
    int SC = best(C);

    vector<pii> vec;
    vec.push_back({SA, 0});
    vec.push_back({SB, 1});
    vec.push_back({SC, 2});
    sort(allof(vec));
    reverse(allof(vec));

    if(vec[0].first == vec[1].first){
        cout << "Draw";
    } else {
        string name[] = {"Kuro", "Shiro", "Katie"};
        cout << name[vec[0].second];
    }
}
