class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> players;
        for(auto i : matches)
        {
            if(players.find(i[0]) == players.end())
                players.insert(make_pair(i[0], 0));
            
            if(players.find(i[1]) == players.end())
                players.insert(make_pair(i[1], 1));
            else
                players[i[1]]++;
        }
        
        vector<vector<int>> result(2);
        for (auto iter = players.begin(); iter != players.end(); ++iter)
        {
           if(iter->second == 0)
               result[0].push_back(iter->first);
            else if(iter->second == 1)
                result[1].push_back(iter->first);
    }
        
        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());
        return result;
    }
};