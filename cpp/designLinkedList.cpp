struct Node {
    int _val;
    Node* _next;
};

class MyLinkedList {
   private:
    Node* _head;
    int _size;
    Node** get_entry(int index) {
        Node** node_ptr = &_head;
        for (int i = 0; *node_ptr != nullptr && i < index;
             node_ptr = &((*node_ptr)->_next), i++)
            ;
        return node_ptr;
    }

   public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        _head = nullptr;
        _size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index) {
        if (index < 0) return -1;

        Node* node = *get_entry(index);
        return node == nullptr ? -1 : node->_val;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked
     * list. */
    void addAtHead(int val) {
        Node* new_head = new Node{._val = val, ._next = _head};
        _head = new_head;
        _size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node** node_ptr = &_head;
        for (; *node_ptr != nullptr; node_ptr = &((*node_ptr)->_next))
            ;
        Node* new_tail = new Node{._val = val, ._next = nullptr};
        *node_ptr = new_tail;
        _size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If
     * index equals to the length of linked list, the node will be appended to
     * the end of linked list. If index is greater than the length, the node
     * will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size) return;
        Node** node_ptr = get_entry(index);
        Node* new_node = new Node{._val = val, ._next = *node_ptr};
        *node_ptr = new_node;

        _size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) return;
        Node** node_ptr = get_entry(index);
        Node* index_node = *node_ptr;
        if (index_node == nullptr) return;
        *node_ptr = index_node->_next;
        delete index_node;

        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
