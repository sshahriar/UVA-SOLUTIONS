// 
#include<bits/stdc++.h>

using namespace std;

#define bound(x,y , i , j) x >= 0 && x < i && y >= 0 && y < j
#define mp make_pair
#define pb push_back
#define pii pair<int , int>
#define M 100
#define rep(i , n) for(i = 0 ; i< n ;i++ )
#define repi(i , n ) for(i =1  ; i<= n ; i++ )
#define mem(x , y ) memset(x , y , sizeof x )
#define mx 5000000
#define ff first
#define ss second
#define sf(x)  scanf("%d", &x ) ;
#define ___  printf("\n");
typedef long long ll ;
//int dx[] = { -1 ,+1, 0 , 0 , -1 , -1  , 1 , 1 };
//int dy[] = { 0 , 0, +1, -1  , +1 , -1 , 1 , -1 };

//int dx[] = { 1 , 1, 2 , 2  , -1 , -1 , -2 , -2 }; // knight direction
//int dy[] = { 2 , -2, +1, -1 ,2 , -2 , 1 , -1 };

vector<int> g[M+5][M] ;
vector<int > cost[M+5][M+5] ;

int dis[5][105][105]  , arr[10000] , temp[10000];


struct make{
  int t , u ,  d  , w ;
    make() {} ;
    make(int a , int b ,int c , int k ){
    t =  a;
    u =  b ;
    d = c ;
    w = k ;

  } ;
  bool operator<(make x ) const { return w > x.w ;     }

};

void clr(){
int i, j , k ;
    rep(i , 5 )rep(j , 100) {
        g[i][j].clear();
        cost[i][j].clear();

    }
    rep(i , 5) rep(j ,100 ) rep(k , 100) dis[i][j][k] = 99999999 ;

}


int dij(int des ){
    int i , j , k ;
    priority_queue<make> pq ;
    pq.push(make(0, 0 ,0 , 0  )) ;
    rep(i ,5)dis[i][0][0] =  0;

    while(!pq.empty()){
        make x =  pq.top() ;
        pq.pop() ;

        int  c = dis[x.t ][x.u ][x.d ] ;
        int u =  x.d ;

    //    if(x.d ==  des ) return c ;
        rep(i , 5) rep(j , g[i][u].size() ){
            int v = g[i][u][j] ;
            int calc = c + cost[i][u][j] ;
            if(u != 0 && i != x.t ) calc += 60  ;
            if(calc < dis[i][u][v]){
                dis[i][u][v] = calc ;
                pq.push(make(i ,u , v , cost[i][u][j] ) ) ;


            }
        }
    }
    return INT_MAX ;
}

int  f(){
    int k ;
    // printf("her \n");
    vector<int> v;
    string line ;
        getline(cin ,line );
        istringstream os(line) ;
        int i ;
        while(os >> i){
            v.push_back(i);

        }
        k = v.size() ;
        rep(i , k ) temp[i] = v[i] ;
       // rep(i, k ) printf("%d ", temp[i] );
        //printf("input taken  \n");
return k ;
}

void solve(){
int i ,j , k , u ,t , d  ;
  
    while(scanf("%d%d",&t ,&d ) ==  2){
    clr()  ;
    rep(i , t  )scanf("%d",&arr[i] ) ;

    getchar();

    rep(j , t ) {
       k = f() ;
    //    printf("here \n");
        for(i = 1 ; i < k ;i++){
            int u =  temp[i] ;
            int v = temp[i-1] ;
            int w ;

            w = u*arr[j] - v* arr[j] ;
            g[j][u].pb(v) ;
            g[j][v].pb(u ) ;

            cost[j][u].pb(w) ;
            cost[j][v].pb(w ) ;

     }
   //  printf("ending lift %d\n",j ) ;
    }

    // printf("asci \n");
    //call(t) ;
  // printf("calling diksta\n");
      
    k = dij(d ) ;
    //printf("\ntaken \n");
    
      if(k == INT_MAX) printf("IMPOSSIBLE\n") ;
    else printf("%d\n",k);

    }
}

int main(){
  freopen("in.txt", "r",stdin );

  int i , j , k , cs= 0 , tc ;
  clr() ;
  solve() ;

  return 0;
}





