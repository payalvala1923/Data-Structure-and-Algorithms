//using pq
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

         
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < dist[v])
                {
                    dist[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }
       
        return dist;
    }



//Dijkstra’s Algorithm – Using Set
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         set<pair<int,int>> st; 

        vector<int> dist(V, 1e9); 
        
        st.insert({0, S}); 

        dist[S] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
           
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                 
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
      
        return dist; 
    }
