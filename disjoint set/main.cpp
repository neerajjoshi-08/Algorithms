#include<bits/stdc++.h>
using namespace std;

vector<int> par, ranks;

int find(int n) {
    if(par[n] == n) {
        return n;
    }
    return par[n] = find(par[n]);   // path compression
}

void union(int u, int v) {
    int parU = find(u);
    int parV = find(v);
    
    if(ranks[parU] > ranks[parV]) {
        par[parV] = parU;
    } else if(ranks[parU] < ranks[parV]) {
        par[parU] = parV;
    } else {
        par[parV] = parU;
        ranks[parU]++;
    }
    
}


int main() {
    int n = 11;
    par.resize(n);
    ranks.resize(n);
    
    for(int i=0; i<n; ++i) {
        par[i] = i;
    }
    
    union(1, 2);
    union(3, 4);
    union(5, 6);
    union(7, 8);
    union(2, 3);
    union(9, 10);
    
    for(int i=0; i<n; ++i) {
        cout << "Node: " << i << " has parent: " << par[i] << endl;
    }
}

/**
 * OUTPUT:
 * Node: 0 has parent: 0
 * Node: 1 has parent: 1
 * Node: 2 has parent: 1
 * Node: 3 has parent: 1
 * Node: 4 has parent: 3
 * Node: 5 has parent: 5
 * Node: 6 has parent: 5
 * Node: 7 has parent: 7
 * Node: 8 has parent: 7
 * Node: 9 has parent: 9
 * Node: 10 has parent: 9
 */