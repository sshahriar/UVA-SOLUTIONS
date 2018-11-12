#include<bits/stdc++.h>
 
using namespace std;
 
#define sz(x) x.size()
#define clr(x) x.clear()
#define mem(x ,y) memset(x , y , sizeof x )
#define all(a ) a.begin() , a.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int , int>
#define endl "\n"
#define makefast()   ios_base :: sync_with_stdio(false ) ; cin.tie(0) ;
#define dbg(args...) do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#define dbgv(v ) rep(i, sz(v) )  cerr << v[i] << ' ' ;  cout << endl ;
#define dbga(x, n) rep(i , n ) cerr << x[i] << ' ' ;  cout << endl
 
#define forn(i,a,n ) for(int  i = a ; i <= n ; i++ )
#define rep(i ,n ) for(int i = 0 ; i < n ; i++ )
#define repi(i ,n ) for(int i = 1 ; i <= n ; i++ )
#define repit(i, c) for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
 
#define si(a) scanf("%d",&a )
#define sl(a) scanf("%I64d",&a )
#define sd(a) scanf("%lf",&a )
#define sii(a , b) scanf("%d %d",&a , &b )
#define siii(a , b , c) sii(a, b ) ; si(c) ;
#define sdd(a , b) scanf("%lf %lf",&a , &b )
#define sll(a , b) scanf("%I64d %I64d",&a , &b )
#define wri(a )  printf("%d\n" , a ) ;
#define wrii(a ,b ) printf("%d %d\n" , a,  b ) ;
#define wrl(a )  printf("%I64d\n" , a ) ;
#define CASE(c ) printf("Case %d: " ,c) ;

int setbit(int n, int pos  ) { return n = n|(1<< pos) ; }
int resetbit(int n,int pos ) {  return n =  n & ~(1<<pos ); }
bool checkbit(int n,int pos ) { return (bool ) (n& (1<<pos))  ; }
 
template< typename T >
void print(const T& v) {
    cerr << v << ' ' ;
}
 
template< typename T1, typename... T2 >
void print( const T1& first, const T2&... rest ){
    print(first);
    print(rest...) ;
}
 
typedef long long LL  ;
typedef unsigned long long  ull ;
typedef vector<int> vi  ;

/////// code from here

const int  mod = 100000000 ; 
const int M = 4001230 ;
const int N =(int)1e8+5 ;
//const int N =10;
const int  inf = 999999999  ; 

int prime[M+2]  ;
vi v;

bool  checkprime(int x) {
    if(x<2 ) return 1; 
    return checkbit( prime[x/30] ,x%30) ;

}

void setval(int x  ) {
    prime[x/30] = setbit(prime[x/30] , x%30 )  ;

}

void bitSeive() {
    forn(i ,2 ,N ) {
        if( checkprime(i)== 0 ) {
            for(int j=i+i; j<N ; j+=i )
                setval(j) ;
        }

    }
    //dbg(checkprime(99) ) ;
    
}

void solve(){   

}

int main ()  {      

     //freopen("in.txt", "r", stdin );
    // freopen( "out.txt", "w",stdout );   
    
    int t=1, k, x,y  ,cnt = 0 ,f ; 
    bitSeive() ;
    rep(i ,N) if(checkprime(i )== 0 ) v.pb(i ) ;
    
    while(scanf("%d", &k ) != EOF )  {
        if(k== 0 ) break ;
        f = 0 ;
        if(k&1) {
            x= 2 ; y=k-2;
            if(checkprime(y)==0 ) {
                f=1; 
            }


        } else{
                
            int yy = upper_bound( all(v), k/2) - v.begin() ; 
            //dbg(yy) ;
            forn(i,yy, sz(v)-1 ) {
                y = v[i ] ;
                x = k-y ; 
                //dbg(x, y ) ;
                if(checkprime(x )==0 and checkprime(y)== 0 ){
                    f=1 ;
                    break ; 
                }



            }






        }
        //dbg("final " ) ;
        if(f) {
            printf("%d is the sum of %d and %d.\n", k ,x,  y ) ;

        } else {

            printf("%d is not the sum of two primes!\n", k ) ;
        }

    }  


    return 0  ;



}





