class Solution {
    long long seek_minimum_time(vector<int> &time, int total_trips, long long begin_time, long long end_time){
        long long mid_time;
        long long mid_trips_number = 0;

        if(begin_time > end_time)
            return -1;
        if(begin_time == end_time)
            return begin_time;

        mid_time = (begin_time + end_time) / 2;
        for(int i = 0; i < time.size(); ++i){
            mid_trips_number += floor((mid_time)/ (long long)time[i]);
        }
        if(mid_trips_number >= total_trips){
            return seek_minimum_time(time, total_trips, begin_time, mid_time);
        }else{
            return seek_minimum_time(time, total_trips, mid_time + 1, end_time);
        }

        return -1;
    }

        
public:
    long long minimumTime(vector<int>& time, int total_trips) {
        long long end_time = 1;
        long long end_time_trips_number = 0;
        for(end_time = 1; end_time < LLONG_MAX; end_time *= 2){
            end_time_trips_number = 0;
            for(int i = 0; i < time.size(); ++i){
                end_time_trips_number += floor((end_time)/ (long long)time[i]);
            }
            if(end_time_trips_number >= total_trips){
                return seek_minimum_time(time, total_trips, end_time/2, end_time);
            }
        }
        return -1;
    }
};
