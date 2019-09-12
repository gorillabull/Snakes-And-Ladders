#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 


using namespace std; 


void dfs(int node, vector<bool> &visited, vector<vector<int>> graph, 
int &count){
    visited[node]=true;
    for(int &x : graph[node]){
        if (!visited[x])
        {
            dfs(x,visited,graph,count);
        }
    }
}

void bfs( vector<vector<int>> &graph, int s  ){
    vector<bool> visited(graph.size()+1); 

    for (size_t i = 0; i < graph.size(); i++)
    {
        visited[i]= false;
    }
    
    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    vector<int>::iterator i ;

    while (!queue.empty())
    {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for ( i = graph[s].begin(); i != graph[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
            
        }
        
    }
    

}

#define V 10000
int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
int minDistance(vector<int> dist, vector<bool> sptSet){
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < dist.size(); v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}



// A utility function to print the constructed distance array 
int printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    bool sptSet[V]; 
    
  
    
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    
    dist[src] = 0; 
  
    
    for (int count = 0; count < V - 1; count++) { 
        
        
        int u = minDistance(dist, sptSet); 
  
        
        sptSet[u] = true; 
  
        
        for (int v = 0; v < V; v++) 
  
            
            
            
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    
    printSolution(dist); 
}
void dijkstra(vector<vector<int>> graph, int src){
    vector<int> dist (graph.size()+1);
    vector<bool> sptSet(graph.size()+1);

    for (size_t i = 0; i < graph.size(); i++)
    {
        dist[i]=INT_MAX;
        sptSet[i] =false;
    }

    dist[src    ] = 0;

    for (size_t count = 0; count < graph.size() - 1 ; count++)
    {
        int u = minDistance(dist,sptSet );

        sptSet[u]=true;

        for (int v = 0; v < graph.size(); v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
            &&dist[u]+graph[u][v] < dist[v])
            {
                dist[v]=dist[u] +graph[u][v];
            }
            
        }
        
    }

    for(int &x : dist){
        cout<<x<<endl;
    }
    
    
}
int main(){

    vector<vector <int >> graph(101);
    vector<pair<int,int>> replace; 
    vector<vector<int>> matGraph(101);
    for (size_t i = 0; i < 101; i++)
    {
        matGraph[i].resize(101);
    }
    
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            matGraph[i][j] = 1;
        }
        
    }
    matGraph[55][66]= 0;
    dijkstra(matGraph,1 );


    
    int n;
    cin>>n;

  for (size_t j = 0; j < n; j++)
  {
        int l,s;
        cin>>l;
        for (size_t i = 0; i < l; i++)
        {
            int a,b;
            cin>>a>>b;
            replace.push_back(make_pair(a,b)); //get the replacables
        }
        cin>>s;
        for (size_t i = 0; i < s; i++)
        {
            int a,b;
            cin>>a>>b;
            replace.push_back(make_pair(a,b));
        }
  }
    
    //initi the graph 
    for (size_t i = 1; i <= 100; i++)
    {
        for (size_t j = 1; j <= 6; j++)
        {
            graph[i].push_back(i+j);
        }
        
    }  

    int iter = 6; 
    //replace nodes with snakees and ladders 
    for(pair<int,int> &x : replace){
        for (size_t i = 0; i < 6; i++)
        {
            if (i==0)
            {
                graph[iter].resize(0);
            }else
            {
                graph[iter-i][i] = x.second; 
            }
            iter+=6;
            if (iter >= graph.size())
            {
                iter=graph.size()-1;
            }
            
            
        }
        
    }

    for(vector<int> & i1 : graph){
        for(int & i2 : i1){
            cout<<i2<<" ";
        }
        cout<<endl;
    }


    
     

    return 0;
}