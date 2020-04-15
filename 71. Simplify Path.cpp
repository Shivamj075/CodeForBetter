class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        
		// ending path with / to make parsing easier
        path += '/';
        string cur = "";
        for (char c : path) {
            if (c == '/') {
                if (!cur.empty()) {
                    // if it's ".." then go back up
                    if (cur == "..") {
                        if (!folders.empty()) {
                            folders.pop_back();
                        }
                    // if it's not ".." or "." then record folder name
                    } else if (cur != ".") {
                        folders.push_back(cur);
                    }
                    
                    // if it's "." do nothing
                }
                
                cur = "";
                continue;
            } 
            
            cur += c;
        }
        
        if (folders.empty()) {
            return "/";
        }
        
        string simplified = "";
        for (auto& folder : folders) {
            simplified += '/' + folder;
        }
        
        return simplified;
    }
};
