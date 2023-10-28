#include <bits/stdc++.h>

using namespace std;

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    
    set<string> seen;
    while (n--) {
        string tp, name;
        cin >> tp >> name;
        bool weird = false;
        if (tp == "entry") {
            weird = seen.count(name);
            cout << name << " entered";
            seen.insert(name);
        } else {
            weird = !seen.count(name);
            cout << name << " exited";
            seen.erase(name);
        }
        if (weird) {
            cout << " (ANOMALY)\n";
        } else {
            cout << "\n";
        }
    }
}
