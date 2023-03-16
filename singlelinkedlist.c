#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}ListNode;  /* 定义节点类型 */
typedef ListNode SingleLinkList;
SingleLinkList *init_list(void); /* 初始化一个带虚拟头的单链表 */
void append_node(SingleLinkList *SSL, DataType x); /* 末尾追加节点 */
void insert_header_node(SingleLinkList *SSL, DataType x); /* 开头插入节点 */
void insert_node_with_index(SingleLinkList *SSL, int i, DataType x); /* 在指定位置插入节点 */
DataType delete_node_with_index(SingleLinkList *SSL, int i); /* 按位置删除节点，返回节点数据  */
int delete_node_with_value(SingleLinkList *SSL, DataType x); /* 按值删除节点，返回节点位置 */
void traverse_list(SingleLinkList *SLL); /* 遍历单链表 */
int locate_node(SingleLinkList *SLL, DataType x); /* 按值查找节点 */
void get_node(SingleLinkList *SLL, int i); /* 按序号查找节点 */

SingleLinkList *init_list(void)
{
    SingleLinkList *head = (SingleLinkList *)malloc(sizeof(SingleLinkList));
    if(head==NULL) exit(-1);
    head->next=NULL;
    return head;
}

void append_node(SingleLinkList *SLL, DataType x)
{
    ListNode *index = SLL;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if(p==NULL) exit(-1);
    p->data = x;
    p->next = NULL;
    while(index->next!=NULL)
    {
        index=index->next;
    }
    index->next = p;
}

void insert_header_node(SingleLinkList *SLL, DataType x)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if(p==NULL) exit(-1);
    p->data = x;
    p->next = SLL->next;
    SLL->next = p;
}

void insert_node_with_index(SingleLinkList *SLL, int i, DataType x)
{
    int j = 0;
    ListNode *index = SLL;
    while(index!=NULL && j<i-1){
        index = index->next;
        j++;
    }
    if(index==NULL) exit(-1);
    else{
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        if(p==NULL) exit(-1);
        p->data = x;
        p->next = index->next;
        index->next=p;
    }
}

void traverse_list(SingleLinkList *SLL)
{
    if(SLL->next==NULL) {
        printf("Empty List!\n");
        exit(-1);
    }
    ListNode *p = SLL->next;
    while(p!= NULL){
        printf("%d", p->data);
        p=p->next;
    }
    printf("\n");
}

DataType delete_node_with_index(SingleLinkList *SLL, int i)
{
    DataType x;
    int j = 0;
    ListNode *index=SLL, *s;
    while(index!=NULL && j<i-1){
        index = index->next;j++;
    }
    if(index==NULL || index->next==NULL) exit(-1);
    else{
        s = index->next;
        index->next = s->next;
        x = s->data;
        free(index->next);
        return x;
    }
}

int locate_node(SingleLinkList *SLL, DataType x){
    int j = 0;
    while(SLL!=NULL){
        if(SLL->data==x) return j;
        else{
            SLL=SLL->next;
            j++;
        }
    }
    return 0;
}

int delete_node_with_value(SingleLinkList *SLL, DataType x)
{
    ListNode *f=SLL, *b=SLL;
    int j=0;
    while(b!=NULL && b->data!=x){
        b=b->next;
        if(j>0) f=f->next;
        j++;
    }
    if(b==NULL) exit(-1);
    f->next=b->next;
    free(b);
    return j;
}

void get_node(SingleLinkList *SLL, int i)
{
    ListNode *p; int j;
    p = SLL->next; j=1;
    while(p!=NULL && j<i){
        p = p->next;j++;
    }
    if(p==NULL) exit(-1);
    if(j==i) printf("%d\t",p->data);
    else printf("Not Found!\n");
}

int main(void)
{
    SingleLinkList *L = init_list();
    append_node(L, 2);
    insert_header_node(L, 0);
    insert_node_with_index(L, 2, 1);
    append_node(L, 6);
    insert_header_node(L, 5);
    insert_node_with_index(L, 2, 4);
    delete_node_with_value(L, 2);
    traverse_list(L);
    get_node(L, 6);
    return 0;
}
