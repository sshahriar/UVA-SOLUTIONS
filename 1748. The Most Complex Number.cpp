#include <bits/stdc++.h> 
using namespace std; 
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define mp              make_pair
#define sz(x)           (int)x.size()
#define mem(x ,y)       memset(x , y , sizeof x )
#define all(a )         a.begin() , a.end()  
#define pii             pair<int,int >
#define endl            "\n"  
#define forn(i,x,y )    for(int i= x; i<=y ; i++ )  
#define ford(i,x,y )    for(int i= x; i>=y ; i-- )  
#define rep(i,n )       for(int i= 0; i<n ; i++ ) 
#define repi(i,n )      for(int i= 1; i<=n ; i++ ) 
#define repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
#ifndef ONLINE_JUDGE           
    #define dbg(args...)    do {   cout << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#else 
    #define dbg(args...)   ; 
#endif 
typedef long long ll  ;
typedef unsigned long long ull  ;
ll  mod =  1e9+7, mod2 =     998244353;
int setbit(int n, int pos  ) { return n = n|(1LL<< pos) ; }
int resetbit(int n,int pos ) { return n = n & ~(1LL<<pos ); }
bool checkbit(int n,int pos) { return (bool ) (n&(1LL<<pos))  ; }
template<typename T>T add(T x, T y, T mod = mod ){ x%= mod ;  y%= mod ;   return (x+y)%mod ;  }
template<typename T>T sub(T x, T y, T mod = mod ){ return ((x-y)%mod+mod )%mod;  }
template<typename T>T mul(T x, T y, T mod = mod ){ x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template<typename T> void print(const T& v) {    cout << v << ' ' ;}
template<typename T1,typename... T2> void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
template<typename T> void dbg_a(T a[] ,int n=10 ) {cerr << "[ "; for(int i=0;i <= n ; i++ )cerr<<a[i]<<' ' ; cerr<< " ]" <<  endl; } 
template<typename F,typename S>ostream& operator<<( ostream& os, const pair< F, S > & p ){return os << "[ " << p.first << ", " << p.second << " ]";}
template<typename T>ostream &operator<<(ostream & os, const vector< T > &v ){os << "[ "; for(int i=0; i<sz(v) ; i++ )  os << v[i] << ' ' ; return os << " ]\n" ; } 
template<typename T>ostream &operator<<(ostream & os, const map< T ,T> &Map ){os << "[ "; repit(it , Map ) os << "[" <<(*it).ff << ' ' << (*it).ss << "] "    ; return os << "]\n" ; } 
template<typename T>ostream &operator<<(ostream & os, const set< T > &Set  ){os << "[ "; repit(it , Set ) os <<  *it  << ' ' ; return os << " ]\n" ; }  
template<typename T>ostream &operator<<(ostream & os, const multiset< T > &Set) {os << "[ "; repit(it , Set )os <<  *it  << ' ' ; return os << " ]\n" ; }  
#define  int  ll      
const int maxn  = (int)  2e5  +  123;
const int inf  =  1e9; //0xc0  ;//0x3f ;    
/////////////////////////////////////////////////

int n ,m,sum    ;    
int a[maxn ],  res_num , res_cnt  ;
 bitset< maxn > prime  ; 
vector< int > v_primes   ;  
void  seive(  )  {
    forn(i,2,1000 ) if( !prime[i]){ 
        for(int j=i*i  ; j<1000  ;j+=i ) {
            prime[ j  ]  = 1 ;
        }  
    }
    forn(i,2, 1000 )if(!prime[i]) v_primes.pb(i)  ;  
 
}
vector<pii >v ; 
void  func(int id , int curr_num , int curr_cnt    )  {
    // dbg(curr_cnt  ,curr_num  , n , curr_num  ) ;
    if(curr_num > n  ) return  ;   
   
    if(curr_cnt>= res_cnt   and curr_num<= n   ) {
        res_num =  curr_num   ; 
        res_cnt = curr_cnt ;
        v.pb(mp(curr_num ,curr_cnt  )  )  ; 
        // dbg(res_num , curr_num   )  
    }

    int x =  v_primes[id]  ; 
    int cn = 1  ; 
    while( 1  )   {
        if( curr_num > n/x ) break  ;  
        cn++  ;  
        curr_num *= x ; 
        if(curr_num >  n ) break;
        func( id+1,  curr_num , curr_cnt* cn )  ;  
    }


}
void  solve() {        
    int x,y,z,p,q  ,  tot = 0  , ans = 0 , mx =0 , mn     ;     
    int res = 1 ; 
    cin >>   n; 

    res_num =  1e18+123 ; 
    res_cnt =  0 ; ; 

    func(0 , 1 ,  1  )  ; 
    
    sort(all(v) )  ; 
    reverse(all(v)  ) ; 
    res_num = v[0].ff  ; 
    rep( i , sz( v) )  {
        if( v[i].ss == res_cnt)res_num = min(res_num,v[i].ff) ;
    }

    cout  << res_num  << ' '  <<   res_cnt <<  endl ; 
    v.clear()  ;  
}       
 //  before submit  -> //  check case 1 
 
signed main() {     
    #ifndef  ONLINE_JUDGE  
        freopen("in.txt", "r", stdin); 
    #endif
    ios :: sync_with_stdio(false);  cin.tie(0); cout.tie(0)  ;      
    cout << fixed << setprecision( 12) ; 
    int t = 1 , cs =0   ;   
    
    seive()   ;   
    cin >> t  ; 
    while(t--)   {   
        // cout <<  "Case #"<<  ++cs << ": " ; 
        solve()  ;   
    }  
    return 0 ;      
}         


  #include <bits/stdc++.h> 
using namespace std; 
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define mp              make_pair
#define sz(x)           (int)x.size()
#define mem(x ,y)       memset(x , y , sizeof x )
#define all(a )         a.begin() , a.end()  
#define pii             pair<int,int >
#define endl            "\n"  
#define forn(i,x,y )    for(int i= x; i<=y ; i++ )  
#define ford(i,x,y )    for(int i= x; i>=y ; i-- )  
#define rep(i,n )       for(int i= 0; i<n ; i++ ) 
#define repi(i,n )      for(int i= 1; i<=n ; i++ ) 
#define repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
#ifndef ONLINE_JUDGE           
    #define dbg(args...)    do {   cout << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#else 
    #define dbg(args...)   ; 
#endif 
typedef long long ll  ;
typedef unsigned long long ull  ;
ll  mod =  1e9+7, mod2 =     998244353;
int setbit(int n, int pos  ) { return n = n|(1LL<< pos) ; }
int resetbit(int n,int pos ) { return n = n & ~(1LL<<pos ); }
bool checkbit(int n,int pos) { return (bool ) (n&(1LL<<pos))  ; }
template<typename T>T add(T x, T y, T mod = mod ){ x%= mod ;  y%= mod ;   return (x+y)%mod ;  }
template<typename T>T sub(T x, T y, T mod = mod ){ return ((x-y)%mod+mod )%mod;  }
template<typename T>T mul(T x, T y, T mod = mod ){ x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template<typename T> void print(const T& v) {    cout << v << ' ' ;}
template<typename T1,typename... T2> void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
template<typename T> void dbg_a(T a[] ,int n=10 ) {cerr << "[ "; for(int i=0;i <= n ; i++ )cerr<<a[i]<<' ' ; cerr<< " ]" <<  endl; } 
template<typename F,typename S>ostream& operator<<( ostream& os, const pair< F, S > & p ){return os << "[ " << p.first << ", " << p.second << " ]";}
template<typename T>ostream &operator<<(ostream & os, const vector< T > &v ){os << "[ "; for(int i=0; i<sz(v) ; i++ )  os << v[i] << ' ' ; return os << " ]\n" ; } 
template<typename T>ostream &operator<<(ostream & os, const map< T ,T> &Map ){os << "[ "; repit(it , Map ) os << "[" <<(*it).ff << ' ' << (*it).ss << "] "    ; return os << "]\n" ; } 
template<typename T>ostream &operator<<(ostream & os, const set< T > &Set  ){os << "[ "; repit(it , Set ) os <<  *it  << ' ' ; return os << " ]\n" ; }  
template<typename T>ostream &operator<<(ostream & os, const multiset< T > &Set) {os << "[ "; repit(it , Set )os <<  *it  << ' ' ; return os << " ]\n" ; }  
#define  int  ll      
const int maxn  = (int)  2e5  +  123;
const int inf  =  1e9; //0xc0  ;//0x3f ;    
/////////////////////////////////////////////////

int n ,m,sum    ;    
int a[maxn ],  res_num , res_cnt  ;
 bitset< maxn > prime  ; 
vector< int > v_primes   ;  
void  seive(  )  {
    forn(i,2,1000 ) if( !prime[i]){ 
        for(int j=i*i  ; j<1000  ;j+=i ) {
            prime[ j  ]  = 1 ;
        }  
    }
    forn(i,2, 1000 )if(!prime[i]) v_primes.pb(i)  ;  
 
}
vector<pii >v ; 
void  func(int id , int curr_num , int curr_cnt    )  {
    // dbg(curr_cnt  ,curr_num  , n , curr_num  ) ;
    if(curr_num > n  ) return  ;   
   
    if(curr_cnt>= res_cnt   and curr_num<= n   ) {
        res_num =  curr_num   ; 
        res_cnt = curr_cnt ;
        v.pb(mp(curr_num ,curr_cnt  )  )  ; 
        // dbg(res_num , curr_num   )  
    }

    int x =  v_primes[id]  ; 
    int cn = 1  ; 
    while( 1  )   {
        if( curr_num > n/x ) break  ;  
        cn++  ;  
        curr_num *= x ; 
        if(curr_num >  n ) break;
        func( id+1,  curr_num , curr_cnt* cn )  ;  
    }


}
void  solve() {        
    int x,y,z,p,q  ,  tot = 0  , ans = 0 , mx =0 , mn     ;     
    int res = 1 ; 
    cin >>   n; 

    res_num =  1e18+123 ; 
    res_cnt =  0 ; ; 

    func(0 , 1 ,  1  )  ; 
    
    sort(all(v) )  ; 
    reverse(all(v)  ) ; 
    res_num = v[0].ff  ; 
    rep( i , sz( v) )  {
        if( v[i].ss == res_cnt)res_num = min(res_num,v[i].ff) ;
    }

    cout  << res_num  << ' '  <<   res_cnt <<  endl ; 
    v.clear()  ;  
}       
 //  before submit  -> //  check case 1 
 
signed main() {     
    #ifndef  ONLINE_JUDGE  
        freopen("in.txt", "r", stdin); 
    #endif
    ios :: sync_with_stdio(false);  cin.tie(0); cout.tie(0)  ;      
    cout << fixed << setprecision( 12) ; 
    int t = 1 , cs =0   ;   
    
    seive()   ;   
    cin >> t  ; 
    while(t--)   {   
        // cout <<  "Case #"<<  ++cs << ": " ; 
        solve()  ;   
    }  
    return 0 ;      
}         


  
