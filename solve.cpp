#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3+6;
char a[N][N];
 int r,c;
 bool vis[N][N];
 vector<pii> path = {{-1,0},{1,0},{0,-1},{0,1}};

 bool valid(int ci,int cj)
 {
     if(ci >= 0 && ci < r &&
         cj >=0 && cj < c &&
          a[ci][cj]=='.')
        return true;
     else
        return false;
 }


 void dfs(int si,int sj)
 {
     vis[si][sj] = true;
     for(int i=0;i<4;i++)
     {
         pii p = path[i];
         int ci = si + p.first;
         int cj = sj + p.second;

         if(valid(ci,cj) && !vis[ci][cj])
         {
             dfs(ci,cj);
         }
     }


 }

int main()
{
    cin>>r>>c;


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
                cin>>a[i][j];

        }
    }
    int countRoom =0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j] || a[i][j]== '#')continue;
                    countRoom++;
                    dfs(i,j);
        }
    }

    cout<<countRoom<<endl;



}
