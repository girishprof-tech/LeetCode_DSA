class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(students[i]);
        }   

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                cnt = 0;
            }
            else {
                int temp = q.front();
                q.pop();
                q.push(temp);
                i--;
                cnt++;
            }

            if (cnt == q.size()) break;
        }

        return q.size();
    }
};