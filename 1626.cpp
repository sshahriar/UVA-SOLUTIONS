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
 
template < typename T > T mul(T x, T y   ) { x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template < typename T > T add(T x, T y  ) { x %= mod ; y %= mod ; return (x+y)%mod ;  }
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
 
const int M = (int )2e6+5;  
const int mx  = 4000+23  ;
 
 
////  code from here ...  
int   n ,a[M+2] , b[M +2 ] , m  , CNT  = 0LL   ;
int dp[200][200] , vis[200][200] , k , d= 0 ; 
string s   ; 
int nxt[200][200 ] ;
bool match(int i,int j ) {
    if(s[i]=='(' and s[j] == ')' ) return 1 ; 
    if(s[i]=='[' and s[j] == ']' ) return 1 ; 
    return 0; 

} 

int func(int i ,int j  )  {
    //dbg( i, j) ;
    if(i> j) return  0; 
    if(i == j ) return 1 ;  

    int &ans  =dp[i][ j],t= 0   , &v_flag = vis[i][j] ; 
    if(ans!= -1  ) return ans ;
    
    ans = inf ;

    if(match(i,j ) ) {

        ans = min( ans, func(i+1, j-1) ) ;
        nxt[i][j] = -1 ;
    }   

    forn(k ,i , j-1 ) {   
        t =  func(i, k )  + func(k+1, j )  ;  
        if(t < ans ){
            ans = t ;
            nxt[i][j]  = k; 
        }
    } 

    return ans ;


}

void go(int i ,int j ) {
  //  dbg(i,j) ; 
    if(i>j) return;
    if( i==j ) {
        if(s[i]==')' or s[i] == '('   ) cout << "()" ; 
        else cout << "[]" ; 
      //  cout << endl ; 
        return ;
    }
    if( nxt[i][j] == -1 ) {
       //dbg("d fadf" ,i ,j) ;
        cout << s[i] ; 
        go(i+1 ,j-1) ; 
        cout << s[j] ; 

    }  else {
        go(i ,nxt[i][j] ) ;
        go(nxt[i][j]+1 ,j ) ; 

    }



 // //   dbg( i ,j ) ;
 //    int t = dp[i][j] ; 
 //    if( match(i ,j ) and dp[i+1][j-1] == t  ) {
 //         //dbg("d fadf" ,i ,j) ;
 //        cout << s[i] ; 
 //        go(i+1 ,j-1) ; 
 //        cout << s[j] ; 

 //    } else {
     
 //        forn(k ,i, j-1)  {
 //            if(dp[i][k ]+dp[k+1][j] ==t  ) {
 //           //     dbg("inside " ,i, j ,k);
 //                go(i ,k  ) ; 
 //                go(k+1,j) ; 
 //                return; 
 //            }


 //        }
 //    }
    
}
void solve( ) {
   // cerr<< "program running ... " <<  endl ; 
    ++d ;
    cin >> s; 
    mem(dp,-1  ) ;
    mem(nxt, -1  );
    int x = func( 0, sz(s )-1 ) ; 
    go(0 , sz(s)-1 ) ; 
 
    cout << endl ; 

}

 
int main() {
    #ifndef ONLINE_JUDGE
       freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
    #endif
    ios ::sync_with_stdio(false);  cin.tie(0); cout.tie(0) ;  

    int t=1 , c = 0 ;  

     
      cin >> t;
    while(t-- ) {
      //  cout << ++c  << ' ' ; 
        if( c>0) 
        cout << endl ; 
        c =1 ; 
        solve() ;
     
    }   
    return 0 ;
       
} 

// dont let your dreams be dreams ...  
