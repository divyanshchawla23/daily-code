class Solution {
public:

    map<string,string> mpp;
    int id = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shrt = "http://tinyurl.com/" + to_string(id);
        mpp[shrt]=longUrl;
        id++;
        return shrt;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));