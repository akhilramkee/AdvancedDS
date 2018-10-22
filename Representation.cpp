#include<iostream>
#include<list>
using namespace std;

class Graph
{
  int v;

  list<int> *adj;

public:
    Graph(int v);

    void addEdge(int v,int w);

    void BFS(int s);

    void DFS(int s);
};

Graph::Graph(int V)
{
    this->v=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

/*BFS Implementation*/

void Graph::BFS(int s)
{
   bool *visited=new bool[v];
   for(int i=0;i<v;i++)
   {
      visited[i]=false;
   }
   list<int> queue;

   visited[s]=true;

   queue.push_back(s);

   while(!queue.empty())
   {
      s=queue.front();
      cout<<s<<" ";
      queue.pop_front();

      for (list<int>::iterator i=adj[s].begin();i!=adj[s].end();++i)
      {
          if(!visited[*i])
          {
            visited[*i]=true;
            queue.push_back(*i);
          }
      }
   }
}

/*DFS Implementation*/

void Graph::DFS(int s)
{
    bool * visited = new bool[v];

    for(int i=0;i<v;i++)
    {
      visited[i]=false;
    }

    list<int> stack;
    visited[s]=true;
    stack.push_back(s);

    while(!stack.empty())
    {
      s=stack.back();
      cout<<s<<" ";
      stack.pop_back();

      for(list<int>::iterator i=adj[s].begin();i!=adj[s].end();++i)
      {
        if(!visited[*i])
        {
          visited[*i]=true;
          stack.push_back(*i);
        }
      }
    }
}



int main()
{
  int val1,val2;
  Graph g(4);
  for(int i=0;i<4;i++)
  {
    cout<<"...";
    cin>>val1;
    if(val1<4)
    {
      g.addEdge(i,val1);
      cin>>val2;
      if(val2==10){
          --i;
      }
    }
  }
  g.BFS(2);
  cout<<endl;
  g.DFS(2);
}
