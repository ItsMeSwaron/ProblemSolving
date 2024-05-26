class Solution 
{
public:

    void TailInserter(ListNode * &head, ListNode * &tail, int val)
    {
        ListNode * NewNode = new ListNode(val);

        if(head == NULL)
        {
            head = NewNode;
            tail = NewNode;
            return;
        }

        tail->next = NewNode;
        tail = NewNode;
    }

    ListNode * mergeNodes(ListNode * head) 
    {
        ListNode * Head = NULL;
        ListNode * Tail = NULL;

        ListNode * tmp = head->next;
        int Total = 0;

        while(tmp != NULL)
        {
            if(tmp->val != 0)
            {
                Total = Total + tmp->val;
                tmp = tmp->next;
            }
            else
            {
                TailInserter(Head,Tail,Total);
                Total = 0;
                tmp = tmp->next;
            }
            
        }
        
        return Head;
    }

    
};