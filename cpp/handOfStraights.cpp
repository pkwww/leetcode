#include <vector>
#include <map>
using namespace std;
class Solution {
public:    
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 1) {
            return true;
        }
        map<int, int> card_freq_map{};
        for (int card: hand) {
            if (card_freq_map.find(card) == card_freq_map.end()) {
                card_freq_map[card] = 1;
            } else {
                card_freq_map[card]++;
            }
        }
        
        while (card_freq_map.size() > 0) {
            int curr = card_freq_map.begin()->first;
            for (int i = curr; i < curr + W; i++) {
                auto it = card_freq_map.find(i);
                if (card_freq_map.find(i) == card_freq_map.end()) {
                    return false;
                }
                if (it->second == 1) {
                    card_freq_map.erase(it);
                }
                it->second--;
            }
        }
        return true;
    }
};
