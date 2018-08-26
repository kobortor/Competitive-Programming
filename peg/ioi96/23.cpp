#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int fact[9];
pii par[40320];

int get_id(vector<int> vec){
    assert(vec.size() == 8);

    int ans = 0;
    for(int a = 0; a < 8; a++){
        ans += fact[7 - a] * vec[a];
        for(int b = a + 1; b < 8; b++){
            if(vec[b] > vec[a]){
                vec[b]--;
            }
        }
    }

    return ans;
}

vector<int> op_A(vector<int> vec){
    reverse(allof(vec));
    return vec;
}
vector<int> op_B(vector<int> vec){
    rotate(vec.begin(), vec.begin() + 3, vec.begin() + 4);
    rotate(vec.begin() + 4, vec.begin() + 5, vec.end());
    return vec;
}
vector<int> op_C(vector<int> vec){
    swap(vec[1], vec[2]);
    swap(vec[1], vec[6]);
    swap(vec[5], vec[6]);
    return vec;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    fact[0] = 1;
    for(int a = 1; a < 9; a++){
        fact[a] = fact[a - 1] * a;
    }

    vector<int> start;
    for(int a = 0; a < 8; a++){
        start.push_back(a);
    }

    queue<vector<int>> q;
    q.push(start);

    memset(par, -1, sizeof par);
    par[get_id(start)] = pii(0, 0);

    while(!q.empty()){
        vector<int> fr = q.front();
        q.pop();

        int id_fr = get_id(fr);

        vector<int> A = op_A(fr);
        vector<int> B = op_B(fr);
        vector<int> C = op_C(fr);

        int id_A = get_id(A);
        int id_B = get_id(B);
        int id_C = get_id(C);

        if(par[id_A].first == -1){
            par[id_A] = pii(id_fr, 'A');
            q.push(A);
        }

        if(par[id_B].first == -1){
            par[id_B] = pii(id_fr, 'B');
            q.push(B);
        }

        if(par[id_C].first == -1){
            par[id_C] = pii(id_fr, 'C');
            q.push(C);
        }
    }

    vector<int> targ;
    for(int a = 1; a <= 8; a++){
        int x;
        cin >> x;
        targ.push_back(x - 1);
    }

    vector<char> ans;
    int cur = get_id(targ);
    while(cur != 0){
        ans.push_back(par[cur].second);
        cur = par[cur].first;
    }

    reverse(allof(ans));

    cout << ans.size() << "\n";
    for(char c : ans){
        cout << c << "\n";
    }
}
