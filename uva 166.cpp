 /*

problem  chaise  hocce - 
    tmr kase kisu coin ase ,,, tmi oigula diye shop keeper k X  amount  pay korba
    make sure korte hobe coin  transaction  ta minimum  hoccce 
    ( tmi shopkeeper  k  j coin  gula dicco +  shop keeper tmk j coin gula back korbe )

idea - 

    case1 : tmi  shopkeeper  k  xactly  minimum coin use kore X  amount pay korla... aita    
            final hote  pare abar  nao  hote  pare ,,,, 
            aita 2d  dp  diye kora jai  ...  amar code er give_shopkeeper  part  dekhte paro ...

    case2 :  tmi  shopkeeper  k  minimum coin use kore X er cheye beshi  amount
            pay korla ,,,,  (  say u paid ... extra_coins )
            ai khetre shopkeeper tmk  return korbe ... shop_return  = (extra_coins - X ) coins ...;


            shopkeeper  ai amount ta (shop_return )  tmk  minimum number of coins use kore 
            return  korbe  obviously,,,, 
            shop keeper r kase sob typer coin infinite times kore ase ... tar mane hocce
            ai part ta classic coin  change dp diye solve kora jabe ,,,,  
            amar code r proceess part ta dekhte paro,,,  dp_extra te  aita save korsi,,, 


    


    
    
    




*/






#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define mp              make_pair
#define sz(x)           (int)x.size()
#define mem(x ,y)       memset(x , y , sizeof x )
#define all(a )         a.begin() , a.end()
#define endl            "\n"
#define pii             pair<int,int> 
#define clr(x)          x.clear()
#define sl(x )          scanf("%I64d" ,&x)
#define si(x )          scanf("%d" ,&x)
#define forn(i ,x,n )   for(int i = x ; i <= n ; i++ )
#define ford(i ,x,n )   for(int i = x ; i >= n ; i-- )
#define rep(i,n )       for(int i= 0; i<n ; i++ ) 
#define repi(i,n )      for(int i= 1; i<=n ; i++ ) 
#define repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
   
typedef long long ll  ;
ll mod =  1e9+7, mod2 = 998244353 ; 
typedef unsigned long long  ull ;
 
#define  int  ll   
const int maxn  = (int)1e6 +  1234 ;
const ll inf  =    1e18 ; //  0xc0  ; //0x3f ; // 
//////////////////////////////////////////////

int coin[]  =  {5,10,20 ,50 ,100 , 200  }   ; 
int dp_extra[maxn ]  , dp[200][1000+50] , a[maxn  ]   ; 
vector<int> coins ;  
int want ; 

void read_input () {
    int f=1 ; 
    double xx; 

    forn(i,1,6 ) cin >>a[i ]   ; 
    forn(i,1,6 ) if( a[i]>0)  f= 0 ; 
    if(f)  {
        exit(0)  ;  
    }

    cin >> xx ; 
    xx  =  xx*100  + .5 ; 
    want  = xx  ;  
  
    forn(i,1,6)  {
        forn(j ,1, a[i] )  coins.pb(  coin[i-1]  )  ; 
    }
  
}
 
void  process()  {


    // shop keeper r kase sob type er coin  infinite times ase ... n
    // ai part ta classic coin change  dp  ... ,
    // mane hocce  x amount of  mone minimim koto coin use kore make kora somvob .., 

    forn(i ,1,1000)  dp_extra[i ] = inf ;   

    forn(i ,1 ,1000)  {
        rep( j ,6 ) {
            int x = coin[j]  ;


            if(i>=x  and  dp_extra[i-x]< inf )  {
                dp_extra[i]  = min(dp_extra[i] ,  dp_extra[i-x]+1 ) ;   

            }
        }
    }

 
}

// tmr kase je coin  gula ase  oigula  use kore  ... 
// shop keeper k   X amount  pay korte minimum koyta coin lagbe aita 
// find out korar jonno ai function ta,,,, 
int give_shopkeeper(int id ,int make)  {
    if(make < 0) return inf ; 
    if(make == 0 )  return 0 ;  
    if(id>= sz(coins) )   {
        return  inf ;  
    }

    int &ans =  dp[id][make] ; 
    if(ans!=-1)  return ans ;

    ans =  inf ; 

    ans =  give_shopkeeper(id+1, make )  ;  //  dont use current coin 
    ans = min(give_shopkeeper(id+1,make-coins[id] )+1  , ans   ) ;  // use current coin 
 
    return  ans ; 



}
void  solve() {
    int  k,x,y  ,f = 0  , ans=  0 ,w , d ,n , m       ;

    coins.clear() ;
    read_input()  ; 
    
    mem(dp,-1) ;

    ans = inf ; 
    int j= 0 ; 
    for(int i = want   ; i<= 1000 ; i++ , j++   )  {
        //  shop keeper k  i amount pay kortesi  minimum amount coin use kore,,, ( 2d coin change dp )
        
        // shop keeper  (want-i ) amount  back korbe ,,, minimum amount coin use kore 
        // shop keeper kase all kind of coin ase tai ,,, ai part ta classic coin change dp diye
        // kora jai ,,,, 


        ans =  min( ans , give_shopkeeper(0,i) +  dp_extra[j ] )  ;

    }
    cout << setw(3) <<  ans  << endl ;





}
signed main() { 
    #ifndef ONLINE_JUDGE           
        freopen("in.txt", "r", stdin);
             freopen("out.txt", "w", stdout) ; 
    #endif 
    // ios :: sync_with_stdio(false);  cin.tie(0);   cout.tie(0) ;     
    // cout << fixed << setprecision(12) ;
    int  c = 0 ,t = 1000   ;  
    // cin>>t  ; 

    process() ; 
    while(1) {
        solve() ;  
    }
      

    return 0 ;    
}     



