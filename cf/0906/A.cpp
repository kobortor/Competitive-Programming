#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool allow[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fill(allow, allow + 26, true);

    int N;
    cin >> N;

    bool uniq_det = false;
    int ans = 0;

    for(int i = 0; i < N; i++){
        string tp, str;
        cin >> tp >> str;

        set<char> incl;
        for(char c : str){
            incl.insert(c);
        }

        if(tp == "."){ //does not contain letter
            for(int a = 0; a < 26; a++){
                if(incl.count(char(a + 'a'))){
                    allow[a] = false;
                }
            }
        } else if (tp == "!") { //contains letter
            if(uniq_det){
                ans++;
            }
            for(int a = 0; a < 26; a++){
                if(!incl.count(char(a + 'a'))){
                    allow[a] = false;
                }
            }
        } else {
            if(uniq_det && i != N - 1){
                ans++;
            }
            allow[str[0] - 'a'] = false;
        }

        int cnt = 0;
        for(int a = 0; a < 26; a++){
            if(allow[a]){
                cnt++;
            }
        }
        if(cnt == 1){
            uniq_det = true;
        }
    }
    cout << ans;
}
