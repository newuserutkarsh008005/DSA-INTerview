
   #include<iostream>
   using namespace std;

   
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        for(int i = 0; i <= k; i++) {

            vector<int> temp = dist;

            for(auto u : flights) {

                int st = u[0];
                int en = u[1];
                int we = u[2];

                if(dist[st] != 1e9 &&
                   dist[st] + we < temp[en]) {

                    temp[en] = dist[st] + we;
                }
            }

            dist = temp;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
    int main(){
        vector<vector<int>>flight={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
        int src = 0, dst = 3, k = 1;
        int ans=findCheapestPrice(4,flight,src,dst,k);
        cout<<ans;
        return 0;
    }
