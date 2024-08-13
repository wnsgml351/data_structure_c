#include "BinaryTree.h"

#include <stdio.h>
#include <stdlib.h>

// 노드를 생성하고 주소를 반환하기
BTreeNode* BTreeNodeCreate(int data) {
    BTreeNode* node = (BTreeNode*)calloc(1, sizeof(BTreeNode));
    node->leftNode = NULL;
    node->rightNode = NULL;
    node->data = data;
    return node;
}

// 노드의 데이터를 가져오기
int GetNodeData(BTreeNode* node) {
    return node->data;
}

// 노드의 왼쪽 자식 노드를 생성하기
void CreateLeftChildNode(BTreeNode* parent, BTreeNode* child) {
    // 만약 이미 부모에게 왼쪽 자식이 있다면 제거하고 추가
    if(parent->leftNode != NULL) {
        free(parent->leftNode);
    }
    parent->leftNode = child;
}

// 노드의 오른쪽 자식 노드를 생성하기
void CreateRightChildNode(BTreeNode* parent, BTreeNode* child) {
    // 만약 이미 부모에게 왼쪽 자식이 있다면 제거하고 추가
    if(parent->rightNode != NULL) {
        free(parent->rightNode);
    }
    parent->rightNode = child;
}

// 전위 순회
void Preorder(BTreeNode* node) {
    if(node == NULL) return;
    // 방문한 노드를 출력한다
    printf("%c ", (char)(node->data + 65));
    // 왼쪽 자식을 방문한다
    Preorder(node->leftNode);
    // 오른쪽 자식을 방문한다
    Preorder(node->rightNode);
}

void Inorder(BTreeNode* node) {
    if(node == NULL) return;
    Inorder(node->leftNode); // 왼쪽으로 이동한다
    printf("%c ", (char)(node->data + 65)); // 방문 체크
    Inorder(node->rightNode); // 오른쪽 자식으로 이동
}

void PostOrder(BTreeNode* node) {
    if(node == NULL) return;
    PostOrder(node->leftNode);
    PostOrder(node->rightNode);
    printf("%c ", (char)(node->data + 65)); // 방문 체크
}


void BinaryTreeMain() {
    BTreeNode* rootNode = BTreeNodeCreate(0);
    BTreeNode* node1 = BTreeNodeCreate(1);
    BTreeNode* node2 = BTreeNodeCreate(2);
    BTreeNode* node3 = BTreeNodeCreate(3);
    BTreeNode* node4 = BTreeNodeCreate(4);
    BTreeNode* node5 = BTreeNodeCreate(5);
    BTreeNode* node6 = BTreeNodeCreate(6);
    BTreeNode* node7 = BTreeNodeCreate(7);
    BTreeNode* node8 = BTreeNodeCreate(8);
    BTreeNode* node9 = BTreeNodeCreate(9);
    BTreeNode* node10 = BTreeNodeCreate(10);
    BTreeNode* node11 = BTreeNodeCreate(11);

    CreateLeftChildNode(rootNode, node1);
    CreateRightChildNode(rootNode, node2);

    CreateLeftChildNode(node1, node3);
    CreateRightChildNode(node1, node4);

    CreateLeftChildNode(node2, node5);
    CreateRightChildNode(node2, node6);

    CreateLeftChildNode(node3, node7);

    CreateLeftChildNode(node4, node8);
    CreateRightChildNode(node4, node9);

    CreateLeftChildNode(node5, node10);
    CreateRightChildNode(node5, node11);

    /***********************************/
    puts("===== PREORDER =====");
    Preorder(rootNode);

    puts("");
    puts("===== INORDER =====");
    Inorder(rootNode);

    puts("");
    puts("===== POSTORDER =====");
    PostOrder(rootNode);
}