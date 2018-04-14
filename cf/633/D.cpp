#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1002;

unordered_map<int, int> ump;

int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int num0 = 0;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        ump[arr[a]]++;
        if(!arr[a]){
            num0++;
        }
    }
    if(num0 > 60){
        cout << num0;
        return 0;
    }

    int best = 0;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            if(a == b){
                continue;
            }
            ll f1 = arr[a], f2 = arr[b];
            vector<ll> used;
            used.push_back(f1);
            ump[f1]--;

            while(ump.count(f2) && ump[f2] != 0){
                ump[f2]--;
                used.push_back(f2);
                
                f2 += f1;
                f1 = f2 - f1;
            }

            for(int i : used){
                ump[i]++;
            }

            best = max(best, (int)used.size());
        }
    }
    cout << best;
}
