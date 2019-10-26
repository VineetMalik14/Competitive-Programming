/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    int m=B,n=C;
    if(m==n)return A;
    
    ListNode* cur;
    ListNode* prev;
    
    int cnt=1;
    ListNode* tempn=A;
    while(cnt!=n+1){
        tempn=tempn->next;
        cnt++;
    }
    
    cnt=1;
    ListNode* tempm=A;
    while(cnt<m-1){
        tempm=tempm->next;
        cnt++;
    }
    
    
    cnt=1;
    cur=A;
    while(cnt!=B){
        cur=cur->next;
        cnt++;
    }
    
    prev=NULL;
    cnt=m;
    while(cnt!=n+1){
        ListNode* temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
        cnt++;
    }
    
    
    ListNode* ans;
    if(m==1){
        ans=prev;
        while(prev->next){
            prev=prev->next;
        }
        prev->next=tempn;
    }else{
        ans=A;
        tempm->next=prev;
        while(prev->next){
            prev=prev->next;
        }
        prev->next=tempn;
        
    }
    
    return ans;
}
