//dont let your dreams be dreams

#include<bits/stdc++.h>

using namespace std;

#define M 1000
#define mp make_pair
#define pb push_back
#define pii pair<int , int>
#define sq(x )  x*x
#define rep(i , n) for(i = 0 ; i< n ;i++ )
#define repi(i , n ) for(i =1  ; i<= n ; i++ )
#define mem(x , y ) memset(x , y , sizeof x )
#define mx 5000000
#define ff first
#define ss second
#define sf1(x)  scanf("%d", &x ) ;
#define sf2(x, y  ) scanf("%d%d",  &x, &y) ;

typedef long long ll ;
//int dx[] = { -1 ,+1, 0 , 0 , -1 , -1  , 1 , 1 };
//int dy[] = { 0 , 0, +1, -1  , +1 , -1 , 1 , -1 };

//int dx[] = { 1 , 1, 2 , 2  , -1 , -1 , -2 , -2 }; // knight direction
//int dy[] = { 2 , -2, +1, -1 ,2 , -2 , 1 , -1 };

vector<int >g[M+5 ] ,stk  , add ;

int arr[101] , vis[M+5]  , f  ;

void clr(){
	int i  , j , k;
	rep(i ,M  ) g[i].clear() ;
	mem(vis , -1 ) ;
	stk.clear() ;

}


void dfs(int u ){
	vis[u] =  1;
	int i ,j ,  k ;

	rep(i , g[u].size() ) {
		int v = g[u][i] ;
		if(vis[v] ==  -1) {
			dfs(v ) ;
		}
	}

stk.pb(u) ;

}

void solve(int n  ) {
	int i , j, k ;
    mem(vis , -1 )  ;
    repi(i , n ) if(vis[i] == -1 )
        dfs(i ) ;
	for(i = stk.size() -1 ; i >= 0 ; i--)
        if( i !=  0 )
            printf("%d ", stk[i] ) ;
        else printf("%d", stk[i] ) ;

        printf("\n") ;



}

int main(){
//	freopen("in.txt", "r",stdin );

	int i , j , k , cs= 0 , tc ,n , m  ;

	while(scanf("%d%d",&n , &m ) ) {
	clr() ;

        if( n == 0 && m  ==  0) break ;
        while(m--){
            sf2(i ,j ) ;
            g[i].pb(j ) ;
            //g[j].pb(i ) ;


        }
        solve( n ) ;

	}

	return 0;
}






