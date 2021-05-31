#include<bits/stdc++.h>
#define INF 9999
#define MAX 10
using namespace std;

void LinkState();
void DistanceVector();

void DistanceVector()
{
    int graph[50][50];
    int i,j,k,t;
    int nn;
    cout<<"\n Enter Number of Nodes:";
    cin>>nn;
    for (i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            graph[i][j]=-1;
        }
    }
    char ch[7]={'A','B','C','D','E','F','G'};
    for (i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            if(i==j)
            {
                graph[i][j]=0;
            }
            if(graph[i][j]==-1)
            {
                cout<<"\n Enter Distance between "<<ch[i]<<" - "<<ch[j]<<" : ";
                cin>>t;
                graph[i][j]=graph[j][i]=t;
            }
        }
    }
    int via[50][50];
    for (i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            via[i][j]=-1;
        }
    }
    cout<<"\n After Initialization";
    for (i=0;i<nn;i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<nn;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<graph[i][j]<<"\t"<<via[i][j];
        }
    }
    int sh[50][50][50];
    for(i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            for (k=0;k<nn;k++)
            {
                if((graph[i][j]>-1)&&(graph[j][k]>-1))
                {
                    sh[i][j][k]=graph[j][k]+graph[i][j];
                }
                else
                {
                    sh[i][j][k]=-1;
                }
            }
        }
    }
    for(i=0;i<nn;i++)
    {
        cout<<"\n\n For "<<ch[i];
        for (j=0;j<nn;j++)
        {
            cout<<"\n From "<<ch[j];
            for(k=0;k<nn;k++)
            {
                cout<<"\n "<<ch[k]<<" "<<sh[i][j][k];
            }
        }
    }
    int final[50][50];
    for(i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            final[i][j]=graph[i][j];
            via[i][j]=i;
            for(k=0;k<nn;k++)
            {
                 
                if((final[i][j]>sh[i][k][j]) || (final[i][j] == -1))
                {
                    if(sh[i][k][j]>-1)
                    {
                        final[i][j]=sh[i][k][j];
                        via[i][j]=k;
                    }
                }
            } 
            if(final[i][j]==-1)
            {
                for(k=0;k<nn;k++)
                {
                    if((final[i][k]!=-1)&&(final[k][j]!=-1))
                    {
                        if((final[i][j]==-1) || ((final[i][j]!=-1) &&(final[i][j]>final[i][k]+final[k][j]))) 
                        {
                            if(final[i][k]+final[k][j]>-1)
                            {
                                final[i][j]=final[i][k]+final[k][j];
                                via[i][j]=k;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"\n After Update :";
    for (i=0;i<nn;i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<nn;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<final[i][j]<<"\t";
            if(i==via[i][j])
                cout<<"-";
            else
                cout<<ch[via[i][j]];
        }
    }
    cout<<"\n\n-----------------------------\n\n";
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INF;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            if(distance[i]!=9999)
            {
                cout<<"\nDistance of the node "<<i<<" = "<<distance[i];
                cout<<"\nPath = "<<i;
                j=i;
                do
                {
                    j=pred[j];
                    cout<<"<-"<<j;
                }while(j!=startnode);
                cout<<"\n";
            }
            else
            {
                cout<<"\nDistance of the node "<<i<<" = INF";;
                cout<<"\nNo path";
            }
        }
        cout<<"\n-----------------------------\n\n";
}
void LinkState()
{
    int G[MAX][MAX],i,j,n,u;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"\nEnter the adjacency matrix:\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>G[i][j];
    while(true)
    {
        cout<<"\nEnter the source/start node: ";
        cin>>u;
        dijkstra(G,n,u);
    }
    
}

int main()
{
    system("cls");
    while(true)
    {
        cout<<"---------Unicast Routing Main Menu--------\n          by [VIBHU KUMAR SINGH]\n\n";
        cout<<"1.Distance Vector Routing\n2.Link State Routing\n0.Exit\nEnter your choice: ";
        int choice;
        cin>>choice;
        cout<<"----------------------------------------------------------------------------\n\n";
        switch(choice)
        {
            case 1:
                DistanceVector();
                break;
            case 2:
                LinkState();
                break;
            case 0:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Choice\n";
                break;
        }
    }
}
