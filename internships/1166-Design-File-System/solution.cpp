class FileSystem {
	map<string, int> mp;
public:
    FileSystem() {
    }
    
    bool createPath(string path, int value) {
		for (int i = 1; i < path.size(); ++i)
		{
			if (path[i] =='/')
			{
				if (mp.find(path.substr(0, i)) == mp.end())
						return false;
			}
		}

		if (mp.find(path) != mp.end())
			return false;

		mp[path] = value;
		return true;
    }
    
    int get(string path) {
		if (mp.find(path) != mp.end())
		{
			return mp[path];
		}
		return -1;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
