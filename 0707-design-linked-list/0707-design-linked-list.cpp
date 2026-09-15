class MyLinkedList {
public:

    // 1. Node
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = NULL;
        }
    };

    // 2. Head
    ListNode* head;

    // 3. Constructor
    MyLinkedList() {
        head = NULL;
    }

    // 4. Get value
    int get(int index) {
        ListNode* curr = head;

        for (int i = 0; i < index; i++) {
            if (curr == NULL)
                return -1;

            curr = curr->next;
        }

        if (curr == NULL)
            return -1;

        return curr->val;
    }

    // 5. Add at beginning
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);

        newNode->next = head;
        head = newNode;
    }

    // 6. Add at end
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        ListNode* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    // 7. Add at index
    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++) {
            if (curr == NULL)
                return;

            curr = curr->next;
        }

        if (curr == NULL)
            return;

        ListNode* newNode = new ListNode(val);

        newNode->next = curr->next;
        curr->next = newNode;
    }

    // 8. Delete at index
    void deleteAtIndex(int index) {

        if (head == NULL)
            return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++) {
            if (curr->next == NULL)
                return;

            curr = curr->next;
        }

        if (curr->next == NULL)
            return;

        ListNode* temp = curr->next;

        curr->next = curr->next->next;

        delete temp;
    }
};