#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i != a.size(); ++i)
#define al(a) a.begin(),a.end()
#define ve vector
#define pb push_back
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

int original[100010], anss[1010]; 


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, m, q;
    in >> n >> m;
    fo(i, n) {
    	in >> original[i];
    	original[i] *= 2;
    }
    fo(i, 1001) {
    	fo(j, n) {
    		anss[i] += min(i, original[j]); 
    	}
    	anss[i] -= (min(i, original[0]) + min(i, original[n - 1])) / 2;
    }
    fo(i, m) {
    	in >> q;
    }
}