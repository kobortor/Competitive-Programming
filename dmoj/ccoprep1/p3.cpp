#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int dsu[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

struct node {
    pii val;
    int prio, sz;
    node *l, *r;
    node(pii p){
        val = p;
        prio = rand();
        sz = 1;
        l = r = nullptr;
    }
    ~node(){
        if(l) delete l;
        if(r) delete r;
    }
};

void pushup(node* rt){
    if(rt != nullptr){
        rt->sz = 1;
        if(rt->l){
            rt->sz += rt->l->sz;
        }
        if(rt->r){
            rt->sz += rt->r->sz;
        }
    }
}

void split(node* rt, node*& l, node*& r, pii val){
    if(rt == nullptr){
        l = r = nullptr;
    } else if (rt->val <= val){
        split(rt->r, rt->r, r, val);
        l = rt;
    } else {
        split(rt->l, l, rt->l, val);
        r = rt;
    }
    pushup(rt);
}

void merge(node*& rt, node* l, node* r){
    if(l == nullptr || r == nullptr){
        rt = max(l, r);
    } else if (l->prio > r->prio){
        merge(l->r, l->r, r);
        rt = l;
    } else {
        merge(r->l, l, r->l);
        rt = r;
    }
    pushup(rt);
}

node* insert(node* rt, node* ins){
    if(rt == nullptr){
        return ins;
    }
    if(rt->prio > ins->prio){
        if(ins->val <= rt->val){
            rt->l = insert(rt->l, ins);
        } else {
            rt->r = insert(rt->r, ins);
        }
    } else {
        split(rt, ins->l, ins->r, ins->val);
        rt = ins;
    }

    pushup(rt);
    return rt;
}

void dfs_ins(node* rt, node*& ins){
    if(rt == nullptr){
        return;
    }

    ins = insert(ins, new node(rt->val));
    dfs_ins(rt->l, ins);
    dfs_ins(rt->r, ins);
}

int nth(node* rt, int n){
    int l = rt->l ? rt->l->sz : 0;
    if(n <= l){
        return nth(rt->l, n);
    } else if (n == l + 1){
        return rt->val.second;
    } else {
        return nth(rt->r, n - l - 1);
    }
}

node *root[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        dsu[a] = a;
        int x;
        cin >> x;
        root[a] = new node({x, a});
    }

    while(M--){
        int u, v;
        cin >> u >> v;
        int fu = find(u);
        int fv = find(v);
        if(fu != fv){
            if(root[fu]->sz < root[fv]->sz){
                swap(fu, fv);
            }

            dsu[fv] = fu;
            dfs_ins(root[fv], root[fu]);
        }
    }

    int Q;
    cin >> Q;

    while(Q--){
        char ch;
        cin >> ch;
        int u, v;
        cin >> u >> v;
        if(ch == 'B'){
            int fu = find(u);
            int fv = find(v);
            if(fu != fv){
                if(root[fu]->sz < root[fv]->sz){
                    swap(fu, fv);
                }

                dsu[fv] = fu;
                dfs_ins(root[fv], root[fu]);
                delete root[fv];
            }
        } else {
            int fu = find(u);
            if(root[fu]->sz < v){
                cout << "-1\n";
            } else {
                cout << nth(root[fu], v) << "\n";
            }
        }
    }
}
