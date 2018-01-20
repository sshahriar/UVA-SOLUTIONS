//dont let your dreams be dreams

#include<bits/stdc++.h>

using namespace std;

#define M 100005
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

int  dp[110][50000 ]  ;
int tot  , lim ;
int arr[200] ;

void clr() {
int i , j  ;
	rep(i , 110) rep(j , 50000) dp[i][j] = -1 ;

}

int f(int  val ) {
	val *= 2 ;
	return  abs(tot - val ) ;

}


int call(int i , int val   ) {
	if(i >=  lim  )
		return  dp[i][val ] = f(val ) ;
  	if(dp[i][val] != -1)  return dp[i][val]  ;

 	return dp[i][val] =  min(call(i+1 ,val + arr[i] ) , call(i +1  ,val )) ;
}

int main(){
	//freopen("in.txt", "r",stdin );
	
	int i , j , k , cs= 0 , tc ;
	sf1(tc ) ;
	while(tc--){
		clr()  ;

		sf1(k ) ;
		rep(i , k )  sf1(arr[i] ) ;
 		lim =  k ;
 		tot = 0 ;
 		rep(i , k ) tot+=  arr[i] ;
 		cout <<  call( 0, 0  ) << endl  ;

	}
	return 0;
}





