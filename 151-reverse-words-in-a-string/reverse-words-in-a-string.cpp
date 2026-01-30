class Solution {
public:
    void reverseRange(string &s, int l, int r) {
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

    string reverseWords(string s) {
        int n = s.size();

        // Step 1: Reverse whole string
        reverseRange(s, 0, n - 1);

        int idx = 0;  // write index

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                // Add space before word if needed
                if (idx > 0) s[idx++] = ' ';

                int j = i;
                // Copy the word
                while (j < n && s[j] != ' ') {
                    s[idx++] = s[j++];
                }

                // Reverse the word back
                reverseRange(s, idx - (j - i), idx - 1);

                i = j;
            }
        }

        // Resize to remove extra trailing chars
        s.resize(idx);
        return s;
    }
};
