class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> st;
        ListNode* temp = head;

        while (temp) {
            while (!st.empty() && st.back()->val < temp->val) {
                st.pop_back();
            }

            st.push_back(temp);
            temp = temp->next;
        }

        for (int i = 0; i < st.size() - 1; i++) {
            st[i]->next = st[i + 1];
        }

        st.back()->next = nullptr;

        return st[0];
    }
};