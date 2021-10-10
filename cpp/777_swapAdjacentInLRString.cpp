class Solution {
public:
    bool canTransform(string start, string end) {
        for (int i = 0, j = 0; ; i++, j++) {
            while (start[i] == 'X' && i < start.size())
                i++;
            while (end[j] == 'X' && j < end.size())
                j++;
            if ((i < start.size() && j == end.size()) || (i == start.size() && j < end.size()))
                return false;
            if (i == start.size() && j == end.size())
                return true;
            if (start[i] != end[j])
                return false;
            if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                return false;
        }
    }
};
