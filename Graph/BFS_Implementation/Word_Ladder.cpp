#include<iostream>
using namespace std;

    int ladderLength(string bw, string ew, vector<string>& wl) {
        unordered_map<string,int>mp;
        for(string i:wl){
            mp[i]++;
        }
        if(mp.find(ew)==mp.end())return 0;
        queue<pair<string,int>>q;
        q.push({bw,1});
        mp.erase(bw);
        while(!q.empty()){
            
            auto pr=q.front();
            q.pop();
            string wrd=pr.first;
            int val=pr.second;
            if(wrd==ew)return val;
            for(int i=0;i<wrd.size();i++){
                char c=wrd[i];
                for(int j=97;j<123;j++){
                    if(j==c)continue;
                    wrd[i]=j;
                    if(mp.find(wrd)!=mp.end()){
                        q.push({wrd,val+1});
                        mp.erase(wrd);
                    }

                }
                wrd[i]=c;
            }
        }
        return 0;
    }

    int main(){
       string beginWord = "hit", endWord = "cog";
      vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
      cout<<ladderLength(beginWord,endWord,wordList);
        return 0;
    }
