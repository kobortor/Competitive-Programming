#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
bool vis[1005];
int arr[51];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }
    for(int a = N - 1; a >= 0; a--){
        if(!vis[arr[a]]){
            vis[arr[a]] = true;
        } else {
            arr[a] = -1;
        }
    }

    vector<int> vec;
    for(int a = 0; a < N; a++){
        if(arr[a] != -1){
            vec.push_back(arr[a]);
        }
    }
    cout << vec.size() << endl;
    for(int i : vec){
        cout << i << " ";
    }
}
