#include<bits/stdc++.h>
using namespace std;
typedef long int li;
typedef long double ld;

vector<vector<ld>> gauss_eli(vector<vector<ld>> adj)
{
     int p=adj.size();
    int q=adj[0].size();
    int maxrow;
    ld maxele;
    for(int i=0;i<p;i++)
    {
        maxele=fabsl(adj[i][i]);
        maxrow=i;
        for(int k=i+1;k<p;k++)
        {
           if(maxele<fabsl(adj[k][i]))
           {
             maxele=fabsl(adj[k][i]);
             maxrow=k;
           }
        }
        swap(adj[i],adj[maxrow]);

        for(li j=i+1;j<p;j++)
        {
            ld factor=adj[j][i]/adj[i][i];
            for(li k=i;k<q;k++)
            {
                adj[j][k]-=factor*adj[i][k];
            }
        }
    }
    return adj;
}

vector<ld> back_substitution(vector<vector<ld>> adj)
{
    int p = adj.size();
    vector<ld> solution(p);

    // Back Substitution
    for (int i = p - 1; i >= 0; i--)
    {
        ld sum = 0;
        for (int j = i + 1; j < p; j++)
        {
            sum += adj[i][j] * solution[j];
        }
        solution[i] = (adj[i][p] - sum) / adj[i][i];
    }
    return solution;
}

vector<vector<ld>> gauss_jordan(vector<vector<ld>> adj)
{
    int p=adj.size();
    int q=adj[0].size();
    for(int i=p-1;i>=0;i--)
    {
        for (int k = 0; k < i; ++k) {
            ld factor = adj[k][i]/adj[i][i];
            for (int j = i; j <=p; ++j) {
                adj[k][j] -= factor * adj[i][j];
            }
        }
    }
    return adj;


}

vector<vector<ld>> row_echelon(vector<vector<ld>> adj)
{
    int p=adj.size();
    for(int i=0;i<p;i++)
    {
        ld factor=adj[i][i];
        for(int j=0;j<p+1;j++)
        {
            adj[i][j]/=factor;
        }
    }
    return adj;
}

void show(vector<vector<ld>> adj)
{
    int p=adj.size();
    int q=adj[0].size();
    cout<<"\nHere is your matrix :"<<endl;
   for(int i=0;i<p;i++)
   {
    for(int j=0;j<q;j++)
    {
        cout<<adj[i][j]<<"  ";
    }
    cout<<endl;
   }
}

void Gauss_Elimination(vector<vector<ld>> adj)
{

    adj=gauss_eli(adj);
    adj=row_echelon(adj);
    int p = adj.size();
    vector<ld> solution(p);
    for (int i = p - 1; i >= 0; i--)
    {
        ld sum = 0;
        for (int j = i + 1; j < p; j++)
        {
            sum += adj[i][j] * solution[j];
        }
        solution[i] = (adj[i][p] - sum) / adj[i][i];
    }
}

void gauss_jordan_elimination(vector<vector<ld>> adj) {
    adj = gauss_eli(adj);
    show(adj);
    adj = gauss_jordan(adj); 
    show(adj);
    adj = row_echelon(adj);
    show(adj);
    int p=adj.size();
    
    cout<<"The roots are : ";
    for(int i=0;i<p;i++)
    {
        cout<<adj[i][p]<<" , ";
    }
    return;
}




int main()
{
    li n;
    cout<<"Enter variable no.:"<<endl;
    cin>>n;
 vector<vector<ld>> mat(n,vector<ld>(n+1));

 for(int i=0;i<n;i++)
   {
    for(int j=0;j<n+1;j++)
    {
        cin>>mat[i][j];
    }
   }
   show(mat);
  gauss_jordan_elimination(mat);
  return 0;

}
/*
4
1 2 -1 1 6
-1 1 2 -1 3
2 -1 2 2 14
0 3 -4 2 2
*/