#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N;
int knight[MAXN];
string house[MAXN];
vector<int> banner[MAXN];

int dep[MAXN];
vector<string> out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        int b;
        cin >> house[a] >> knight[a] >> b;

        while(b--){
            string s;
            cin >> s;
            banner[a].push_back(find(house, house + a, s) - house);
        }
    }

    for(int a = 0; a < N; a++){
        int soln = -1;
        for(int idx : banner[a]){
            if(knight[idx] >= knight[a] + 3){
                if(soln == -1){
                    soln = idx;
                } else if (knight[idx] > knight[soln]){
                    soln = idx;
                } else if (knight[idx] == knight[soln] && house[idx] < house[soln]){
                    soln = idx;
                }
            }
        }

        if(soln != -1){
            swap(knight[soln], knight[a]);
            swap(house[soln], house[a]);
        }
    }

    int mx = 0;
    for(int a = N - 1; a >= 0; a--){
        for(int idx : banner[a]){
            dep[idx] = dep[a] + 1;
        }
        mx = max(mx, dep[a]);
        out[dep[a]].push_back(house[a]);
    }

    for(int a = 0; a <= mx; a++){
        sort(allof(out[a]));
        for(string s : out[a]){
            cout << s << " ";
        }
        cout << endl;
    }
}
