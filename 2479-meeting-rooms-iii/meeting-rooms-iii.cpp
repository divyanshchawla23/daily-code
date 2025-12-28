class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<long long> last_room_time(n, 0);
        vector<int> room_use_count(n, 0);

        for (auto& it : meetings) {

            long long start_time = it[0];
            long long end_time = it[1];
            bool found = 0;
            long long early_end_time = LLONG_MAX;
            long long early_end_room = LLONG_MAX;
            long long  meeting_time = end_time-start_time;

            for (int room = 0; room < n; room++) {

                if(last_room_time[room]<=start_time){
                    last_room_time[room]=end_time;
                    room_use_count[room]++;
                    found = 1;
                    break;
                }

                if(last_room_time[room]<early_end_time){
                    early_end_time = last_room_time[room];
                    early_end_room = room;
                }

            }

            if(!found){

                last_room_time[early_end_room] += meeting_time;
                room_use_count[early_end_room]++;

            }
        }

        int x = INT_MIN;
        int ans = -1;

        for(int i =0;i<n;i++){
            if(room_use_count[i]>x){
                x = room_use_count[i];
                ans = i;
            }
        }
        return ans;
    }
};