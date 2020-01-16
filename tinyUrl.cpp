map<string, string> urlMap;
    vector<char> charMap{'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int size = charMap.size();
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
    
        string shortUrl = "http://tinyurl.com/";
        int count = 0;
        while(count < 5){
            int index = rand() % size;
            shortUrl += charMap[index];
            count++;
        }
        urlMap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlMap[shortUrl];
    }
