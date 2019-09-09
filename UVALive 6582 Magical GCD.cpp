// idea : if we keep adding new element to gcd either 
//        stays same or decreases  ...
/*
 
Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.
 
- Tooru Oikawa.
 
*/

#include <bits/stdc++.h>
using namespace std; 
  
#define     ff              first
#define     ss              second
#define     pb(x)           push_back(x)
#define     mp              make_pair
#define     sz(x)           x.size()
#define     mem(x ,y)       memset(x , y , sizeof x )
#define     all(a )         a.begin() , a.end()
#define     endl            "\n"
#define     pii             pair<int,int> 
#define     rep(i ,n )      for(int i = 0 ; i < n ; i++ )
#define     repi(i ,n )     for(int i = 1 ; i <= n ; i++ )
#define     forn(i ,x,n )   for(int i = x ; i <= n ; i++ )
#define     ford(i ,x,n )   for(int i = x ; i >= n ; i-- )
#define     repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
#define     dbg(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
  
typedef long long ll  ;
typedef unsigned long long  ull ;
typedef vector<int> vi  ;
 
const int  inf = 0x3f3f3f3f  ;
const int  mod = 1e9+7;
const ll  INF = 1e17+7  ;

int setbit(int n, int pos  ) { return n = n|(1<< pos) ; }
int resetbit(int n,int pos ) {  return n =  n & ~(1<<pos ); }
bool checkbit(int  n,int pos ) { return (bool ) (n&(1<<pos))  ; }
 
template < typename T > T modMul(T x, T y   ) { x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template < typename T > T modAdd (T x, T y  ) { x %= mod ; y %= mod ; return (x+y)%mod ;  }
template < typename T > T modPow(T x, T k ,T mod ) { if(k == 0 ) return 1; if(k&1  ) { return ( (x%mod)*modPow(x,k-1, mod )%mod )%mod ; } else { T ret = modPow(x,k/2 , mod ) ; ret %= mod ; return (ret*ret )%mod; } }
template < typename T > T ext_gcd(T num1 , T num2, T &X , T &Y ) { T r2,r1, q2, q1 , x2, x1, y2 ,y1 , x,  y, r   ; x2 = 1; y2 = 0;  x1 = 0; y1 = 1; for( r2 =num1 ,r1 = num2 ;r1 != 0 ; y2 = y1, y1 = y,x2 = x1 ,x1 = x ,r2 = r1, r1 = r) {q1 = r2/r1; x = x2 - q1*x1; y = y2 - q1*y1; r = r2%r1 ; } X = x2 ; Y = y2 ; return r2 ;  }
template < typename T > void print(const T& v) {    cerr << v << ' ' ;}
template < typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
 
template < typename T > 
T  modInv( T x , T m = 1e9+7) {  
    return modPow(x,m-2 , m) ;   
    // long long ret, t ;// 
    // ext_gcd( x, m ,ret ,t  ) ;
    // ret %= m ; if(ret<0) ret += m  ; 
    // return ret;
} 
 
// debuging ...
template<typename T > 
void dbg_a(T a[] ,int n=10 ) {
    cerr << "[ "; rep(i,n )cerr<<a[i]<<' ' ; cerr<< " ]" <<  endl; 
}
 
template < typename F,  typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "[ " << p.first << ", " << p.second << " ]";
}
 
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "[ "; rep(i , sz( v)  )  os << v[i] << ' ' ; return os << " ]" ; 
} 


//int dx[] = {0 , 0 ,+1, -1 } ;
//int dy[] = {-1, +1,0 , 0 };
 
const int M = (int )1e5+123;  
const int mx  = 4000+23  ;
 
 
////  code from here ...  

ll a[M +2]  ;
void solve( ) {
   // cerr<< "program running ... " <<  endl ; 
//v.clear(); 
    int  q; 
    ll ans = 0  ,n  , len =0  ; 
    //cin >> n ; 
    scanf("%lld", &n )  ;
    
    //v.pb( mp (0,0))  ;
    repi(i,n  ) {
        scanf("%lld", &a[i] )  ;  
    }

    vector< pair<ll, ll > >st ;
    st.pb( mp(a[1], 1)  ) ; 
    ans = a[1] ; 
    
    forn(ii ,2, n) {
        ll g = a[ii]   ; 
        vector< pair<ll, ll > > v1,v2;
        st.pb(mp(g ,ii ) ) ;
        //cout << ii << "-> " << endl ; 
        
        //cout << st<< endl; 
        v1.pb( st[sz(st)-1] ) ;
        ford(i, sz(st )-2 , 0  ) {
            g = __gcd(st[i].ff,v1.back().ff) ;
            //dbg(i, g , st[i].ff, v1.back().ff) ;
            v1.pb(mp( g, st[i].ss  ) ) ;
        }
        reverse(all( v1)) ;
        v1.pb(mp(a[ii], ii )) ; 
        v2.pb(v1[0] ) ;

        forn(i ,1, sz(v1)-1  ) {
            if(v1[i].ff != v2.back().ff ) 
                v2.pb(v1[i]) ; 

        }
 
         st.clear() ;
 
        rep( i , sz(v2) ) {

            ans = max( ans, v2[i].ff*(ii-v2[i].ss+1 ) ) ;  
            st.pb(v2[i] ) ; 

        }
         
    }   
    printf("%lld\n" ,ans ) ;
    
}

 
int main() {
    #ifndef ONLINE_JUDGE
       freopen("in.txt", "r", stdin);
      //   freopen("out.txt", "w", stdout);
    #endif
//    ios ::sync_with_stdio(false);  cin.tie(0); cout.tie(0) ;  

    int t=1 , c = 0 ;
 
    scanf("%d", &t ) ; 
    while(t-- ) {
      //  cout << ++c  << ' ' ; 
        solve() ;
     
    }   
    return 0 ;
       
} 




