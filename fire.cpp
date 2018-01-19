#include<bits/stdc++.h>
using namespace std;

#define M 1015
#define pii pair<int , int >
#define mp make_pair
#define pf printf
#define sf scanf
#define sf1(a ) scanf("%d",&a)
#define pb push_back
#define sf2(a, b) scanf("%d%d",&a ,&b)
#define rep(i,n) for(i = 0 ; i< n ;i++ )

const int mx =  10000000;
vector<int > g[500000];

struct _node{
int x , y ;

}var[100000];

struct _fire{
int x , y ;

};

struct _me{
int x , y ;

};
vector<_fire > fire;
queue<int> q;
vector<_me > me ;

int arr[M][M] , m_arr[M][M];
int dist[1000000] , vis[10000000];

int bfs(int start , int tag);

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);

int i , j , k,tc ;
int cs  = 0;
  sf1(tc );
  while(tc--){
  ++cs;
  int row , col , len;

  char str[M][M];

  rep(i , 500000)g[i].clear();

  fire.clear();
  me.clear();

  scanf("%d%d",&row ,&col );
  getchar();

    for(i = 0 ; i< row ; i++)
     gets(str[i]);
    for(i = 0 ;i< row ; i++){
      for(j = 0 ; j< col ; j++)
      {
        if(str[i][j] == '#') arr[i+1][j+1] = 4;
        else if(str[i][j] == '.') arr[i+1][j+1] = 1;
        else if(str[i][j] == 'F'){
          arr[i+1][j+1] = 1;
          _fire pv ;
          pv.x = i+1 ; pv.y  = j +1;

          fire.pb(pv);
        }
        else if(str[i][j] == 'J') {
          _me pj;
        pj.x = i+1 ;
        pj.y =  j +1;
        me.pb(pj);
          arr[i+1][j+1] = 1;

        }
      }

    }

  int count = 1;
  _node ob;
  for(i = 0 ; i<= col+2 ; i++) {
    m_arr[0][i] = 0 ;
    m_arr[row+1][i] = 0 ;

  }

  for(i = 0 ; i<=row+2; i++) {
    m_arr[i][0] = 0 ;
    m_arr[i][col+1 ] = 0 ;

  }

  for(i = 1 ;i<=  row ; i++){
    for(j=1 ; j<= col ; j++)
    {
      m_arr[i][j] = count;
      var[count].x =i ;
      var[count++].y = j;



    }
  }
  /*pf("ho ho ho,,");
  rep(i , row+2){
    rep(j , col+2 )
    pf("%d ",m_arr[i][j]);
    pf("\n");
  }

  /*/

    for(i = 1 ;i<=  row ; i++){
      for(j=1 ; j<= col ; j++){
//        pf("%d %d-----> ",arr[i][j] , m_arr[i][j]);
  //        pf("%d %d\n", i , j);
      if(arr[i][j] == 4) continue;

      if(arr[i-1][j] == 1 || arr[i-1][j] == 0 )
        g[m_arr[i][j]].pb(m_arr[i-1][j]);

      if(arr[i+1][j] == 1 || arr[i+1][j] == 0 )
        g[m_arr[i][j]].pb(m_arr[i+1][j]);

      if(arr[i][j+1] == 1 || arr[i][j+1] == 0 )
        g[m_arr[i][j]].pb(m_arr[i][j+1]);

      if(arr[i][j-1] == 1 || arr[i][j-1] == 0 )
       g[m_arr[i][j]].pb(m_arr[i][j-1]);

      }
    }
/*
    rep(i , row ){
      rep(j , col)
      {
        k = m_arr[ i+1][j+1];
        pf("%d(%d %d) -> ",k , var[k].x, var[k].y );
        for(int u = 0 ; u < g[k].size() ; u++)
          pf("%d ",g[k][u]);
          pf("\n");


      }
    }



  */
  rep(i ,M ) dist[i] = mx;

  for(i = 0 ;i< fire.size(); i++){
   k =  bfs(m_arr[fire[i].x][fire[i].y] , 2);

  }

  dist[0] =  mx ;
  dist[m_arr[me[0].x][me[0].y]] =  0 ;
  ++cs;

   k = bfs(m_arr[me[0].x][me[0].y] , 10);
    // bfs();
  if(k==  mx )
    pf("IMPOSSIBLE\n");
  else
  pf("%d\n",dist[0]);
  }
return 0 ;
}


int bfs(int start , int tag){
int i, j,k ;


if(!q.empty()) while(!q.empty()) q.pop();

  dist[start] = 0;
  dist[0] = mx;

  q.push(start);
  memset(vis, -1 , sizeof vis );

  vis[start] = 1 ;
  pf("%d %d\n", start , dist[start]);

  int flag = 0;

  while(!q.empty()){
    k = q.front();
    q.pop();
    for(i = 0 ; i< g[k].size() ;i++)
    {
       if(vis[g[k][i] ] == -1){
      vis[g[k][i] ] =  1;

        if(dist[g[k][i] ] > dist[k]+1)
        {
        if(tag == 10)
          pf("val %d %d\n",k, dist[k]);
          dist[g[k][i]] =  dist[k] +1 ;
          if(tag ==  10 && g[k][i] == 0){
                  flag =1 ;
                  break ;
          }

         q.push(g[k][i]);
        }

      }
    }
    if(flag ==1 ) break ;
  }
return dist[0];
}
