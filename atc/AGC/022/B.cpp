#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 30005;

vector<int> used;
vector<int> v0, v2, v3, v4;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }

    for(int a = 1; a <= 30000; a++){
        //we can take a mod 6 = 0, 2, 3, 4
        if(a % 6 == 0){
            v0.push_back(a);
        }
        if(a % 6 == 2){
            v2.push_back(a);
        }
        if(a % 6 == 3){
            v3.push_back(a);
        }
        if(a % 6 == 4){
            v4.push_back(a);
        }
    }

    reverse(allof(v0));
    reverse(allof(v2));
    reverse(allof(v3));
    reverse(allof(v4));

    N -= 2;
    used.push_back(v3.back()); v3.pop_back();
    used.push_back(v3.back()); v3.pop_back();

    N -= 2;
    used.push_back(v2.back()); v2.pop_back();
    used.push_back(v4.back()); v4.pop_back();

    if(N % 2 != 0){
        N--;
        used.push_back(v0.back()); v0.pop_back();
    }

    while(N > 0 && !v3.empty()){
        N -= 2;
        used.push_back(v3.back()); v3.pop_back();
        used.push_back(v3.back()); v3.pop_back();       
    }

    while(N > 0 && !v2.empty()){
        N -= 2;
        used.push_back(v2.back()); v2.pop_back();
        used.push_back(v4.back()); v4.pop_back();       
    }

    while(N > 0){
        N--;
        used.push_back(v0.back()); v0.pop_back();
    }

    for(int i : used){
        cout << i << " ";
    }
}
