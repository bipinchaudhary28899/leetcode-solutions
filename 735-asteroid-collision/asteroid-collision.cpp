class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            bool insert=true;
            while(!st.empty() && asteroids[i]*st.top()<0 ){
                int top = st.top();
                if(asteroids[i]<0 && top>0){
                    if(abs(asteroids[i])<abs(top)){
                        insert=false;
                        break;
                    }else if(abs(asteroids[i])>abs(top)){
                        st.pop();
                    }else{
                        insert=false;
                        st.pop();
                        break;
                    }
                }else if(asteroids[i]>0 && top<0){
                    break;
                }
            }
            if(insert) st.push(asteroids[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};