class MyLinkedList {
private:
    ListNode* dummy;  // sentinel node
    int size;

public:
    MyLinkedList() {
        dummy = new ListNode(0); // dummy does not hold real data
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        ListNode* curr = dummy->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        ListNode* prev = dummy;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        ListNode* node = new ListNode(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        ListNode* prev = dummy;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        ListNode* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
    }
};
