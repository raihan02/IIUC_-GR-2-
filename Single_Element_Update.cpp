//#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cmath>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <string>
#include <cstring>
#include <ctime>

/*Header File ends here*/

/*Macro starts here*/

#define f(i,j,n) for(int i=j; i<n; i++)
#define fu(i,j,n) for(int i=j; i>n; i--)
#define c(x, n) x n; cin>>n
#define ft int t; scanf("%d", &t); for(int c=1; c<=t; c++)
#define w(n) while(n--)
#define visited 1
#define unvisited -1
#define debug printf("\n<<CameHere<<\n")
#define mem(x,y) memset(x, y, sizeof(x))
#define pal(temp) pali(temp, 0, temp.size()-1)
#define nl printf("\n")
#define space printf(" ");
#define eps 1e-9
#define inf 1<<28
#define cases printf("Case %d:", c);
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fin(prob) freopen("prob.in", "r", stdin)
#define fout(prob) freopen("prob.out", "w", stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define cos(a) cos(a*pi/180)
#define sin(a) sin(a*pi/180)
#define tan(a) tan(a*pi/180)
#define cosi(a) acos(a)/(pi/180)
#define sini(a) asin(a)/(pi/180)
#define tani(a) atan(a)/(pi/180)
#define deb(x) cerr<< #x <<"="<<x<<endl;

#define si(a) int a; scanf("%d", &a);
#define sll(a) ll a; scanf("%lld", &a);
#define sllu(a) unsigned ll a; scanf("%llu", &a);
#define sd(a) double a; scanf("%lf", &a);

#define pi(a) printf("%d", a);
#define pll(a) printf("%lld", a);
#define pllu(a) printf("%llu", a);
#define pd(a) printf("%lf", a);

#define p printf
/*Macro Ends here*/

using namespace std;

/*typedef start here*/

const double pi=2*acos(0);

typedef string st;
typedef vector <int> vi;
typedef vector <string> vs;
typedef pair <int, int> ii;
typedef long long ll;
typedef vector < pair <int, int> > vii;
typedef priority_queue<int,vector<int>,greater<int> > min_heap;

/*typedef ends here*/

/*Important functions starts here */

template <class T> T abs (T a, T b=0)
{
    if(b==0) return (a<0) ? -a : a;
    return (a>b) ? (a-b) : (b-a);
}

template <class T> inline T gcd(T a, T b)
{
    if(a<0) return gcd(-a, b);
    if(b<0) return gcd(a,-b);
    return (b==0) ? a : gcd(b, a%b);
}

template <class T> inline ll pow(T a, T b)
{
    if(b==1) return a;
    ll t=pow(a, b/2);
    t*=t;
    if(!(b%2)) return t;
    return a*t;
}

bool pali(string temp, int i, int j)
{
    if(i>=j) return true;
    if(temp[i]==temp[j]) return pali(temp, i+1, j-1);
    return false;
}

/*Important functions ends here*/

/*Debug Extension ends here*/

template <typename F, typename S>
ostream& operator << (ostream& os, const pair< F, S>& p)
{
    return os<<"(" <<p.first<<", "<<p.second<<")";
}

template<typename T> ostream &operator << (ostream &os, const vector<T> &v)
{
    os<<"{";
    typename vector<T> :: const_iterator it;
    for(it= v.begin(); it!=v.end(); it++)
    {
        if(it!=v.begin()) os<<",";
        os<<*it;
    }
    return os<<"}";
}

template <typename T> ostream &operator << (ostream & os, const set<T>&v)
{
    os<<"[";
    typename set<T> :: const_iterator it;
    for(it=v.begin(); it!=v.end(); it++)
    {
        if(it!=v.begin()) os<<",";
        os<<*it;
    }
    return os<<"]";
}

template <typename F, typename S> ostream &operator << (ostream & os, const map<F,S>&v)
{
    os<<"[";
    typename map<F,S>::const_iterator it;

    for(it=v.begin(); it!=v.end(); it++)
    {
        if(it != v.begin()) os<<",";
        os<< it ->first<<"="<<it->second;
    }
    return os<<"]";
}

int arr[100002];
int tree[400002];

void build(int node, int a, int b) {
  	if(a > b) return;
  	if(a == b) {tree[node] = arr[a]; return;}
    build(node*2, a, (a+b)/2);
	build(node*2+1, 1+(a+b)/2, b);
	tree[node] = (tree[node*2]+tree[node*2+1]);
}

int query(int node, int a, int b, int i, int j){
    if(i>b || j<a) return 0;
    if(a>= i && b<= j) return tree[node];
    return query(node*2, a, (a+b)/2, i, j)+query(1+node*2, 1+(a+b)/2, b, i, j);
}

void update1(int node, int a, int b, int i, int val){
    if(i>b || i<a) return ;
    if(a>=i && b<=i){tree[node]+=val; return ;}
    update1(node*2, a, (a+b)/2, i, val);
	update1(node*2+1, 1+(a+b)/2, b, i, val);
	tree[node] = (tree[node*2]+tree[node*2+1]);
}

void update2(int node, int a, int b, int i, int val=0){
    if(i>b || i<a) return ;
    if(a>=i && b<=i){tree[node]=0; return ;}
    update2(node*2, a, (a+b)/2, i, val);
	update2(node*2+1, 1+(a+b)/2, b, i, val);
	tree[node] = (tree[node*2]+tree[node*2+1]);
}

int main(){
    ft{
        cases;nl;
        si(n);si(q);
        f(i,0,n) scanf("%d", &arr[i]);
        build(1, 0, n-1);
        f(i,0,q){
            si(com);
            if(com==1){
                si(sack);
                int lagbe=query(1,0,n-1,sack, sack);
                printf("%d\n", lagbe);
                update2(1,0,n-1,sack);
            }
            else if(com==2){
                si(sack);si(val);
                update1(1,0,n-1,sack,val);
            }
            else{
                si(a);si(b);
                printf("%d\n", query(1,0,n-1,a, b));
            }
        }
    }
return 0;}
