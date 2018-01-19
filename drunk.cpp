//dont let your dreams be dreams

#include<bits/stdc++.h>

using namespace std;

#define M 10000
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

vector<int >g[M+5 ]  , g2[M +5] ,stk  , add ;

int arr[101] , vis[M+5]  , f  ;

void clr(){
	int i  , j , k;
	rep(i ,M  ) g[i].clear() ;
	mem(vis , -1 ) ;
	f =  -1 ;
	stk.clear() ; add.clear() ;

}

struct _ed{
	int u , v ;
	_ed(int a , int b) { u = a; v= b ; } ;
	_ed(){} ;

};

vector<_ed > edge ;

void rev(){
int i  ,u , v;
	rep(i  , edge.size() ){
		u = edge[i].u;
		v = edge[i].v;
		g2[v].pb(u ) ;

	}
}

void dfs1(int u ){
	vis[u] =  1;
	int i ,j ,  k ;

	rep(i , g[u].size() ) {
		int v = g[u][i] ;
		if(vis[v] ==  -1) {
			dfs1(v ) ;
		}

	}

stk.pb(u) ;
}

void dfs(int u ){
int i , j, k ;

	vis[u] =  1 ;
	add.pb(u ) ;

	rep(i , g2[u].size() ){
		int v = g2[u][i] ;
		if(vis[v] ==  -1) {
			dfs(v ) ;
		}
	//	else f = 1 ;
	}
}

void solve(int c )  {
	int i , j , k  ;
	rep(i  , c ) if(vis[i] == -1) 	dfs1(i) ;

	rev() ; mem(vis ,-1 ) ;

	for(i = stk.size() -1  ; i >= 0 ;i++) {
		add.clear();
		dfs(arr[i]  ) ;
		if(add.size() > 1 ){
			f= 1 ;  break ;

		}
	}






}

int main(){
	freopen("in.txt", "r",stdin );

	int i , j , k , cs= 0 , tc ;
	sf1(tc) ;
	while(tc--){
		clr() ;
		int qr , c = 0  ; sf1(qr) ;
		char s1[20] , s2[20] ;

		map<string , int > m ;
		while(qr--){
		scanf("%s %s", s1, s2 ) ;
      //  cout << s1 << " " << s2 << endl  ;
		if(m.find(s1) == m.end() ) m[s1] =  c++;
		if(m.find(s2) == m.end() ) m[s2] =  c++;

            int u =  m[s1] ;
            int v = m[s2] ;
    		edge.pb(_ed(u,v )) ;
           // if(u == v ) continue ;
            g[u].pb(v ) ;
        }

        solve(c) ;

        if(f == 1) printf("Case %d: No\n", ++cs );
		else printf("Case %d: Yes\n",  ++cs ) ;

	}




	return 0;
}






