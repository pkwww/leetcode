#include <string>
#include <map>
using namespace std;
struct Node {
    string value;
    map<char, Node*> children;
    bool is_term;
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        _root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = _root;
        for (char c: word) {
            map<char, Node*>& c_map = curr->children;
            auto search = c_map.find(c);
            if (search == c_map.end()) {
                // not find
                Node* new_node = new Node();
                new_node->value = curr->value + c;
                new_node->is_term = false;
                c_map.insert({c, new_node});
                curr = new_node;
            } else {
                curr = search->second;
            }
        }
        curr->is_term = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* searched = search_node(word);
        return searched != _root && searched->is_term;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return search_node(prefix) != _root;
    }
private:
    Node* _root;
    
    Node* search_common(string word, bool ret_root) {
        if (word.empty()) {
            // won't happen because the question guratee
            return nullptr;
        }
        Node* curr = _root;
        for (char c: word) {
            map<char, Node*>& c_map = curr->children;
            auto search = c_map.find(c);
            if (word == "app") {
                printf("char: %c\n", c);
            }
            if (word == "app") {
                printf("curr s: %s\n", (curr->value).c_str());
            }
            if (search == c_map.end()) {
                // not in trie
                if (ret_root) {
                    return _root;
                } else {
                    return curr;
                }
            } else {
                curr = search->second;
            }
        }
        return curr;
    }
    
    Node* search_node(string word) {
        return search_common(word, true);
    }
    
    Node* search_prefix(string word) {
        return search_common(word, false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
