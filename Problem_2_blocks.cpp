#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MOD 1000000007
int main()
{
    int M,N,P,_i,_j;
    cout<<"Origin is at 1,1 "<<endl;
    cout<<"Enter no. rows then no. column then no. of paths blocked and then their coordinates"<<endl;

    cin>>M>>N>>P;
    ll Grid[M+1][N+1];
    memset(Grid, 0, sizeof(Grid));

    F(i,0,P-1)
    {
        cin>>_i>>_j;
        Grid[_i][_j] = -1;
    }
    if(Grid[1][1] == -1)
    {
        printf("0");
        return 0;
    }
    F(i,1,M)
    {
        if(Grid[i][1] == 0) Grid[i][1] = 1LL;
        else break;
    }
    F(i,2,N)
    {
        if(Grid[1][i] == 0) Grid[1][i] = 1LL;
        else break;
    }
    F(i,2,M)
    {
        F(j,2,N)
        {
            if(Grid[i][j] == -1) continue;

            if(Grid[i-1][j] > 0) Grid[i][j] = (Grid[i][j] + Grid[i-1][j] + MOD)%MOD;
            if(Grid[i][j-1] > 0) Grid[i][j] = (Grid[i][j] + Grid[i][j-1] + MOD)%MOD;
        }
    }

    printf("%lld",(Grid[M][N] >= 0 ? Grid[M][N] : 0));
    return 0;
}
