int countCharacters(vector<string>& words, string chars) {
        map<char,int> freqMap;
        int result = 0;
        for(char c : chars)
            freqMap[c]++;
        for(string word : words){
            auto temp_map = freqMap;
            int i = 0;
            for(char c : word){
                if(temp_map.find(c) != temp_map.end()){
                    temp_map[c]--;
                    i++;
                    if(temp_map[c] == 0)
                        temp_map.erase(c);
                }else
                    break;
            }
            if( i == word.size())
                result += word.size();
        }
        return result;
}