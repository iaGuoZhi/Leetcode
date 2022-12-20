//Class Copy {
//	int movie;
//	int shop;
//	int price;
//	int status;
//
//	Copy(int _movie, int _shop, int _price, int _status): movie(_movie), shop(_shop), price(_price), status(_status) {};
//
//	bool operator < (const Copy &a) const
//	{
//		return this->status < a.status ||
//			(this->status == a.status && this->price < a.price) ||
//			(this->status == a.status && this->price == a.price && this->shop < a.shop);
//	}
//};
//
//Class Movie {
//	int id;
//	priority_queue pq;
//
//	Movie(_id): id(_id);
//
//	void addCopy(int movie, int shop, int price)
//	{
//		if (movie != this->id)
//			return;
//		pq.push(Copy(movie, shop, price, 0));
//	}
//}

class MovieRentingSystem {
	int n;
	vector<int, map<int, int>> unrents;
	vector<int, map<int, int>> rents;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
		this->n = n;
		unrents.resize(n);
		rents.resize(n);

		for (auto entry : entries)
		{
			unrents[entry[0]][entry[1]] = entry[2];
		}
    }
    
    vector<int> search(int movie) {
		vector<int> ans;

		for (int i = 0; i < n; ++i)
		{
			if (unrents[i].find(movie) != unrents[i].end())
			{
				if (ans.size() < 5 || unrents[ans[4]][movie] > unrents[i][movie])
					ans.push_back(i);
				if (ans.size() > 5)
					ans.erase(ans.begin() + 5);
			}
		}
		return ans;
    }
    
    void rent(int shop, int movie) {
		rents[shop][movie] = unrents[shop][movie];
		unrents[shop].erase(movie);
    }
    
    void drop(int shop, int movie) {
		unrents[shop][movie] = rents[shop][movie];
		rents[shop].erase(movie);
    }
    
    vector<vector<int>> report() {

    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
