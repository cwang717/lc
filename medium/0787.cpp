class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //11:00
        unordered_map<int, vector<pair<int, int>>> g;
        for (auto v:flights) {
            if (g.find(v[0]) == g.end()) {
                g[v[0]] = vector<pair<int, int>>{make_pair(v[1], v[2])};
            } else {
                g[v[0]].push_back(make_pair(v[1], v[2]));
            }
        }
        
        //bfs
        
        unordered_map<int, int> min_cost;
        min_cost[src] = 0;
        //city, cost, stops
        queue<vector<int>> q;
        q.push(vector<int>{src, 0, 0});
        while(!q.empty()) {
            auto e = q.front();
            int current_cost = e[1];
            int current_stop = e[2];
            for (auto p:g[e[0]]) {
                int next_city = p.first;
                int delta = p.second;
                int next_cost = delta + current_cost; 
                int next_stop = current_stop+1;
                
                //can't go to next_city
                if (next_stop > k+1) {
                    continue;
                }
                // update min_cost
                if (min_cost.find(next_city)!=min_cost.end()) {
                    if (next_cost >= min_cost[next_city]) {
                        continue;
                    } else {
                        min_cost[next_city] = min(min_cost[next_city], next_cost);
                    }
                } else {
                    min_cost[next_city] = next_cost;
                }
                cout << next_city << ", " << next_cost << ", " << next_stop << endl;
                q.push(vector<int>{next_city, next_cost, next_stop});
            }
            
            q.pop();
        }
        
        return (min_cost.find(dst) != min_cost.end()) ? min_cost[dst] : -1;
    }
};