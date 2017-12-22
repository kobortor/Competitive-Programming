#include<bits/stdc++.h>

using namespace std;

#define allof(x) x.begin(), x.end()

unordered_map<string, vector<string>> ump;

bool is_suffix(const string &base, const string &suf){
    if(base.size() < suf.size()) {
        return false;
    }

    for(int a = 0; a < (int)suf.size(); a++){
        if(base[a] != suf[a]){
            return false;
        }
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        string name;
        cin >> name;
        int K;
        cin >> K;

        vector<string> &to_ins = ump[name];
        while(K--){
            string id;
            cin >> id;
            reverse(id.begin(), id.end());
            to_ins.push_back(id);
        }
    }
    cout << ump.size() << "\n";
    for(auto &au : ump) {
        sort(allof(au.second));
        au.second.erase(unique(allof(au.second)), au.second.end());
        sort(allof(au.second), [](const string &s1, const string &s2) {return s1.size() > s2.size(); });

        vector<string> ans;
        for(int a = 0; a < (int)au.second.size(); a++){
            bool to_use = true;
            for(int b = 0; b < a; b++){
                if(is_suffix(au.second[b], au.second[a])){
                    to_use = false;
                    break;
                }
            }
            if(to_use){
                ans.push_back(au.second[a]);
            }
        }
        cout << au.first << " " << ans.size();
        for(string &str : ans){
            reverse(allof(str));
            cout << " " << str;
        }
        cout << "\n";
    }
}
