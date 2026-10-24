class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        unordered_map<string, int> mpp;
        mpp["01"] = 0;
        mpp["02"] = 31;
        mpp["03"] = 59;
        mpp["04"] = 90;
        mpp["05"] = 120;
        mpp["06"] = 151;
        mpp["07"] = 181;
        mpp["08"] = 212;
        mpp["09"] = 243;
        mpp["10"] = 273;
        mpp["11"] = 304;
        mpp["12"] = 334;

        if (mpp[arriveAlice.substr(0, 2)] > mpp[leaveBob.substr(0, 2)] ||
            mpp[leaveAlice.substr(0, 2)] < mpp[arriveBob.substr(0, 2)]) return 0;

        int start, end;

        if (mpp[arriveAlice.substr(0, 2)] > mpp[arriveBob.substr(0, 2)]) {
            start = mpp[arriveAlice.substr(0, 2)] + stoi(arriveAlice.substr(3));
        }
        else if (mpp[arriveAlice.substr(0, 2)] < mpp[arriveBob.substr(0, 2)]) {
            start = mpp[arriveBob.substr(0, 2)] + stoi(arriveBob.substr(3));
        }
        else if (stoi(arriveBob.substr(3)) > stoi(arriveAlice.substr(3))) {
            start = mpp[arriveBob.substr(0, 2)] + stoi(arriveBob.substr(3));
        }
        else {
            start = mpp[arriveAlice.substr(0, 2)] + stoi(arriveAlice.substr(3));
        }

        if (mpp[leaveAlice.substr(0, 2)] < mpp[leaveBob.substr(0, 2)]) {
            end = mpp[leaveAlice.substr(0, 2)] + stoi(leaveAlice.substr(3));
        }
        else if (mpp[leaveAlice.substr(0, 2)] > mpp[leaveBob.substr(0, 2)]) {
            end = mpp[leaveBob.substr(0, 2)] + stoi(leaveBob.substr(3));
        }
        else if (stoi(leaveBob.substr(3)) > stoi(leaveAlice.substr(3))) {
            end = mpp[leaveAlice.substr(0, 2)] + stoi(leaveAlice.substr(3));
        }
        else {
            end = mpp[leaveBob.substr(0, 2)] + stoi(leaveBob.substr(3));
        }
        
        return end - start + 1 <= 0 ? 0 : end - start + 1;
    }
};