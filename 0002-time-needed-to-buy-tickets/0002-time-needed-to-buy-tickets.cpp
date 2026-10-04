class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        if (n == 0) return 0;
        int time = 0;

        int i = 0;
        while (tickets[k]) {
            if (!tickets[i]) {
                i = (i+1) % n;
                continue;
            }

            tickets[i]--;
            time++;
            i = (i+1) % n;
        }

        return time;
    }
};