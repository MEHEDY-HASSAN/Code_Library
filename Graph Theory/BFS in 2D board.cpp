#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
typedef long long ll;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,+1,-1};
///int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};///King's Move
///int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
///int fx[]={+2,+2,-2,-2,-1,-1,+1,+1};///Knight's Move
///int fy[]={-1,+1,-1,+1,+2,-2,+2,-2};
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int r,c;
    while(1)
    {
        cin>>r>>c;
        if(r==0 && c==0)
            return 0;
        bool vis[r][c];
        int cell[r][c];
        int d[r][c];
        memset(vis,0,sizeof(vis));
        memset(cell,-1,sizeof(cell));
        memset(d,0,sizeof(d));
        int i,j,rows;
        cin>>rows;
        for(i=0; i<rows; i++)
        {
            int x,tot;
            cin>>x>>tot;
            for(j=0; j<tot; j++)
            {
                int p;
                cin>>p;
                cell[x][p]=0;
            }
        }
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        queue< pair<int,int> >q;
        vis[sx][sy]=true;
        pair<int,int>n={sx,sy};
        q.push(n);
        while(!q.empty())
        {
            pair<int,int> x=q.front();
            q.pop();
            for(i=0; i<4; i++)
            {
                int tx=x.first+fx[i];
                int ty=x.second+fy[i];
                if(!vis[tx][ty] && tx>=0 && tx<r && ty>=0 && ty<c && cell[tx][ty])
                {
                    vis[tx][ty]=true;
                    d[tx][ty]=d[x.first][x.second]+1;
                    q.push({tx,ty});
                }
            }
        }
//        for(i=0;i<r;i++)
//        {
//            for(j=0;j<c;j++)
//            {
//                cout<<d[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<d[dx][dy]<<endl;
    }
    return 0;
}
