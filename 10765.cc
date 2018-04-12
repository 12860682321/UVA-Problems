/*
 * Biconnected Components
 *
 * Author: Howard Cheng
 * Date: Oct 15, 2004
 *
 * The routine bicomp() uses DFS to find the biconnected components in
 * a graph.  The graph is stored as an adjacency list.  Use clear_graph()
 * and add_edge() to build the graph.
 *
 * Note: This works only on connected graphs.  See comment below in code.
 *
 * The code simply prints the biconnected components and the articulation
 * points.  Replace the printing code to do whatever is appropriate.
 *
 * NOTE: some articulation points may be printed multiple times.
 *
 *
 */

 #include <iostream>
 #include <stack>
 #include <algorithm>
 #include <cassert>
 #include <vector>
 #include <utility>
 
 using namespace std;
 
 /* maximum number of nodes, maximum degree, and maximum number of edges */
 const int MAX_N = 10001;
 const int MAX_DEG = 200;
 
 struct Node {
   int deg;
   int nbrs[MAX_DEG];
   int dfs, back;
 };
 
 int dfn;
 
 void clear_graph(Node G[], int n)
 {
   int i;
   for (i = 0; i < n; i++) {
     G[i].deg = 0;
   }
 }
 
 void add_edge(Node G[], int u, int v)
 {
   G[u].nbrs[G[u].deg++] = v;
   G[v].nbrs[G[v].deg++] = u;
 }
 
 void do_dfs(Node G[], int v, int pred, stack<int> &v_stack, 
         stack<int> &w_stack, vector<pair<int,int> > &targets)
 {
   int i, w, child = 0;
 
   G[v].dfs = G[v].back = ++dfn;
   for (i = 0; i < G[v].deg; i++) {
     w = G[v].nbrs[i];
     if (G[w].dfs < G[v].dfs && w != pred) {
       /* back edge or unexamined forward edge */
       v_stack.push(v);
       w_stack.push(w);
     }
     if (!G[w].dfs) {
       do_dfs(G, w, v, v_stack, w_stack,targets);
       child++;
 
       /* back up from recursion */
       if (G[w].back >= G[v].dfs) {
     /* new bicomponent */
     /*cout << "edges in new biconnected component:" << endl;
     while (v_stack.top() != v || w_stack.top() != w) {
       cout << v_stack.top() << " " << w_stack.top() << endl;
       v_stack.pop();
       w_stack.pop();
     }
     cout << v_stack.top() << " " << w_stack.top() << endl;
     v_stack.pop();
     w_stack.pop();
    */
     if (pred != -1) {
       //cout << "articulation point: " << v << endl;
       targets.at(v).second++;
     }
       } else {
     G[v].back = min(G[v].back, G[w].back);
       }
     } else {
       /* w has been examined already */
       G[v].back = min(G[v].back, G[w].dfs);
     }
   }
   if (pred == -1 && child > 1) {
     //cout << "articulation point: " << v << endl;
     targets.at(v).second++;
   }
 }
 
 void bicomp(Node G[], int n, vector<pair<int,int> > &targets)
 {
   int i;
   stack<int> v_stack, w_stack;
 
   dfn = 0;
   for (i = 0; i < n; i++) {
     G[i].dfs = 0;
   }
   //do_dfs(G, 0, -1, v_stack, w_stack);
 
   // NOTE: if you wish to process all connected components, you can simply
   // run the following code instead of the line above:
   //
   
    for (int i = 0; i < n; i++) {
      if (G[i].dfs == 0) {
        do_dfs(G, i, -1, v_stack, w_stack,targets);
      }
    }
 }
 
 bool comp(const pair<int,int> &a, const pair<int,int>&b){
     return a.second != b.second? a.second > b.second : a.first < b.first;
 }
 int main(void)
 {
    Node G[MAX_N];
    int n, m, i, u, v;
    int bombs;
    cin >> n >> bombs;
    while(n != 0 && bombs != 0){
        clear_graph(G, n);
        vector<pair<int, int> > targets;
        for(int i = 0; i < n; ++i){
            targets.push_back(make_pair(i,1)); //Made a vector of each nodes bomb value with the 
        }                                      //first being the node and the second being the bomb value.
        cin >> u >> v;
        while(u != -1 && v != -1){
            add_edge(G,u,v);
            cin>>u>>v;
        }
        //cout<<"good"<<endl;
        bicomp(G,n,targets);
        sort(targets.begin(),targets.end(),comp);
        for(int i = 0; i < bombs; ++i){
            cout<<targets.at(i).first<<" "<<targets.at(i).second<<endl;
        }
        cout<<endl;
        cin>>n>>bombs;
    }
   return 0;
 }
 