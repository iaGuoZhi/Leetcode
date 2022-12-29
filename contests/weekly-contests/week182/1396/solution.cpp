class UndergroundSystem {
	map<int, pair<int, string>> in_times;
	map<pair<string, string>, pair<double, double>> averages;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
		in_times[id] = make_pair(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
		pair<int, string> in = in_times[id];
		string in_station = in.second;
		int in_time = in.first;
        double cur_average = 0, cur_n = 0;
        if (averages.find(make_pair(in_station, stationName)) != averages.end())
		{
			cur_average = averages[make_pair(in_station, stationName)].first;
			cur_n = averages[make_pair(in_station, stationName)].second;
		}

		averages[make_pair(in_station, stationName)] = make_pair(((double(t - in_time) + cur_average * cur_n) / (cur_n + 1)), cur_n + 1);
    }
    
    double getAverageTime(string stationName, string endStation) {
		return averages[make_pair(stationName, endStation)].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(stationName,endStation);
 */


