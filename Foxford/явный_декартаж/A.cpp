#include <random>
#include <iostream>
using namespace std;
int mr(){return (rand() << 15) + rand();}
struct nd{
    int x, y, sz = 0;
    nd *l, *r;
    nd():l(nullptr),r(nullptr){}
    nd(int x):x(x),y(mr()),l(nullptr),r(nullptr),sz(1){}
};
typedef nd* pn;
pn x1, x2 ,x3, M_rt;
int g_s(pn rt){return rt ? rt->sz : 0;}
void upd(pn rt){if(rt)rt->sz = g_s(rt->l) + g_s(rt->r) + 1;}
void spl(pn rt, pn& l, pn& r, int x){
    if(!rt) return void(l = r = nullptr);
    if(rt->x < x) {spl(rt->r, rt->r, r, x); l = rt; upd(l);}
    else          {spl(rt->l, l, rt->l, x); r = rt; upd(r);}
}
void mer(pn& rt, pn l, pn r){
    if(!l || !r) return void(rt = l ? l : r);
    if(l->y < r->y) {mer(l->r, l->r, r); rt = l;}
    else            {mer(r->l, l, r->l); rt = r;}
    upd(rt);
}
void ins(pn& rt, int x){
    spl(rt, x1, x2, x);
    mer(rt, x1, new nd(x)); mer(rt, rt, x2);
}
void era(pn& rt, int x){
    spl(rt, x1, x2, x); spl(x2, x2, x3, x + 1);
    mer(rt, x1, x3);
}
void print(pn& rt){
    if(!rt) return;
    print(rt->l);
    cout << rt->x << ' ';
    print(rt->r);
}
/*int g_n(pn rt, int x){
    if(!rt) return 0;
    if(g_s(rt->l) > x) return g_n(rt->l, x);
    if(g_s(rt->l) == x) return g_s(rt->l);
    return g_n(rt, x - g_s(rt->l) - 1);
}*/
bool fnd(pn rt, int x)
{return !rt?false:(rt->x == x?true:(rt->x>x?fnd(rt->l,x):fnd(rt->r,x)));}
int g_i(pn rt, int i)
{return !rt?0:(g_s(rt->l)>i?g_i(rt->l,i):(g_s(rt->l)==i?rt->x:g_i(rt->r,i-g_s(rt->l)-1)));}
int g_n(pn rt, int x)
{return !rt?0:(rt->x==x?g_s(rt->l):(rt->x>x?g_n(rt->l,x):g_n(rt->r,x)+g_s(rt->l)+1));}
int main(){
    int a, b, n;
    srand(42);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a == 1) {cout << g_n(M_rt, -b) << '\n'; ins(M_rt, -b);}
        else era(M_rt, g_i(M_rt, b));
        //print(M_rt);
        //cout << '\n';
    }
    return 0;
}
