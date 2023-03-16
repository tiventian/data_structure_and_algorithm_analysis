#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ListSize 100

/* 定义数据类型 */
typedef int DataType;
typedef struct {
    DataType data[ListSize];
    int length;
} SeqList;

/* 函数声明 */
SeqList *init_list(void);
void insert_node(SeqList *L, int i, DataType x);
DataType delete_node(SeqList *L, int i);
void append_node(SeqList *L, DataType x);
int get_length(SeqList *L);
int is_empty(SeqList *L);
int is_full(SeqList *L);
void traverse_list(SeqList *L);
void clear_list(SeqList *L);
void destroy_list(SeqList **L);
DataType pop_node(SeqList *L);

int main(void)
{
    SeqList *L = init_list();
    printf("表长为%d\n", get_length(L));
    insert_node(L, 1, 1);
    traverse_list(L);
    append_node(L,2);
    append_node(L,3);
    traverse_list(L);
    printf("是否空——%d\n", is_empty(L));
    printf("是否满——%d\n", is_full(L));
    pop_node(L);
    pop_node(L);
    traverse_list(L);
    printf("表长为%d\n", get_length(L));
    clear_list(L);
    printf("表长为%d\n", get_length(L));
    destroy_list(&L);
    printf("%p\n", L);
    traverse_list(L);
    return 0;
}

SeqList *init_list(void)
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    if(L==NULL){
        printf("Initialion Failed!\n");
        exit(-1);
    }
    L->length = 0;
    return L;
}

int get_length(SeqList *L)
{
    if(L)return L->length;
    printf("param error!\n");
    exit(-1);
}

int is_empty(SeqList *L)
{
    return L->length==0 ? 1 : 0;
}

int is_full(SeqList *L)
{
    return L->length == ListSize ? 1 : 0;
}

void insert_node(SeqList *L, int i, DataType x)
{
    int j;
    /* 判断i是否越界 */ 
    if(is_full(L)){
        printf("OverFlow!\n");
        exit(-1);
    }
    if(i < 1 || i > L->length+1 || i > ListSize){
        printf("Position Error!\n");
        exit(-1);
    }
    for(j = L->length-1; j > i; j--){
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = x;
    L->length++;
}

void traverse_list(SeqList *L)
{
    int i;
    for(i=0; i<=L->length-1;i++){
        printf("%d\t",L->data[i]);
    }
    printf("\n");
}

void append_node(SeqList *L, DataType x)
{
    if(is_full(L)){
        printf("Overflow!\n");
        exit(-1);
    }
    L->data[L->length] = x;
    L->length++;
}

DataType delete_node(SeqList *L, int i)
{
    int j;
    DataType x;
    if(i<1 || i>L->length){
        printf("Position Error!\n");
        exit(-1);
    }
    x = L->data[i-1];
    for(j=i-1;j<L->length-1;j++){
        L->data[j] = L->data[j+1];
    }
    L->length--;
    return x;
}

void clear_list(SeqList *L)
{
    L->length = 0;
}

void destroy_list(SeqList **L)
{
    free(*L);
    *L=NULL;
}

DataType pop_node(SeqList *L)
{
    DataType x;
    if(is_empty(L)){
        printf("空表!\n");
        exit(-1);
    }
    x = L->data[L->length-1];
    L->length--;
    return x;
}
