#include <stdio.h>

void main()
{
    printf("first program in VScode \n");

    return;
}
#if 0
// 查找targetNum 在数组seqArray中的位置，返回seqArray的下标, low是起始位置，high是结束位置
int Bisection(int targetNum, int low, int high, int seqArray[])
{
    while (low <= high) {
        int middle = low + ((low - high) / 2); // 这样写防止越界
        if (seqArray[middle] == targetNum) {
            return middle;
        } else if (seqArray[middle] < targetNum) {
            low = middle + 1; // 刷新为middle + 1，而不是Middle,因为middle这个下标对应的元素已经不是我们要找的元素。
        } else {
            high = middle - 1;
        }
    }
    return -1;   
}

// 单向链表节点结构体
typedef struct SingleNodeStru{
    int data; //数据域
    struct SingleNodeStru *nextNode;
} SingleNode;

// 在链表head末尾插入一个节点
SingleNode* AppdenNode(SingleNode *head)
{
    SingleNode* insertNode = NULL;
    insertNode = (SingleNode*)malloc(sizeof(SingleNode));
    if (insertNode == NULL) {
        return NULL;
    }
    insertNode->nextNode = NULL;
    int data;
    scanf("%d", &data);
    insertNode->data = data;

    if (head == NULL) {
        head = insertNode;
    }
    SingleNode* currNode = head;
    while (currNode->nextNode != NULL) {
        currNode = currNode->nextNode;
    }
    currNode->nextNode = insertNode;
    return head;
}


// 插入新单向链表节点, 假设原来的链表head中的信息域已经按照升序排列好，现在将data数据插入链表里面
SingleNode* InsertNode(SingleNode *head, int data)
{
    // 新插入节点初始化
    SingleNode* insertNode = NULL; 
    insertNode = (SingleNode*)malloc(sizeof(SingleNode)); //malloc
    if (insertNode == NULL) { //内存申请校验
        return NULL;
    }
    // 新建节点赋值
    insertNode->nextNode = NULL;
    insertNode->data = data;

    // 目标链是空链处理
    if (head == NULL) {
        head = insertNode;   
    } else { //目标链不是空链
        SingleNode* currNode = head;
        SingleNode* tempNode = NULL;
        // 查找插入位置，当查找到链表末尾或者当前节点数据大于插入节点的数据就停止，所以下面处理分2种情况
        while (currNode->nextNode != NULL && currNode->data < data) {
            tempNode = currNode; // 此处用temp节点临时保存上个节点的值
            currNode = currNode->nextNode;
        }
        // 如果是查到当前节点值大于插入值的处理
        if (currNode->data >= data) {
            if (currNode == head) { // 如果原链表只有1个节点
                insertNode->nextNode = currNode;
                head = insertNode; //需要用head直到第一个节点上
            } else { //如果有多个节点
                tempNode->nextNode = insertNode;
                insertNode->nextNode = currNode;
            }
        } else { // 如果查到链表末尾才强制结束的情况
            currNode->nextNode =insertNode;
        }
    }
    return head;
}

// 删除data所在节点，并返回头节点head
SingleNode* DeleteNode(SingleNode* head, int data)
{
    SingleNode * currNode = NULL;
    if (head == NULL) {
        return NULL;
    }
    currNode = head;
    SingleNode * tempNode = NULL;
    while (currNode->nextNode != NULL && currNode->data != data) {
        tempNode = currNode;
        currNode = currNode->nextNode;
    }
    if (currNode->data == data) {
        if (currNode == head) { // 只有1个节点或者多个节点时刚好第一个节点就是要删除的
            head = currNode->nextNode;
        } else {
            tempNode->nextNode = currNode->nextNode; 
        }
        free(currNode);
    } else {
        // 没有找到需要删除的节点
    }
    return head;
}

// 回环链表判断

int IsLoopList(SingleNode *L)
{
   SingleNode *p1 = L;
   SingleNode *p2 = L;
   if(L->nextNode == NULL) return 0;
   while(p2->nextNode != NULL&&p2->nextNode->nextNode != NULL)
   {
       p2 = p2->nextNode->nextNode;
       p1 = p1->nextNode;
       if(p1 == p2)
       {
           return 1;
       }
   }
   return 0;
}

#endif