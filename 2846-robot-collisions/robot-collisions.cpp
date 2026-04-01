class Solution {
public:
    
struct Robot {
    int position;
    int health;
    char direction;
    int index;
};

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    
    vector<Robot> robots;
    
    for (int i = 0; i < n; i++) {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }
    
    sort(robots.begin(), robots.end(), [](Robot &a, Robot &b) {
        return a.position < b.position;
    });
    
    vector<Robot> st;
    
    for (auto &curr : robots) {
        
        if (curr.direction == 'R') {
            st.push_back(curr);
        } else {
            while (!st.empty() && st.back().direction == 'R') {
                
                if (st.back().health == curr.health) {
                    st.pop_back();
                    curr.health = 0;
                    break;
                } 
                else if (st.back().health > curr.health) {
                    st.back().health -= 1;
                    curr.health = 0;
                    break;
                } 
                else {
                    curr.health -= 1;
                    st.pop_back();
                }
            }
            
            if (curr.health > 0) {
                st.push_back(curr);
            }
        }
    }
    
    sort(st.begin(), st.end(), [](Robot &a, Robot &b) {
        return a.index < b.index;
    });
    
    vector<int> ans;
    for (auto &r : st) {
        ans.push_back(r.health);
    }
    
    return ans;
}
};
