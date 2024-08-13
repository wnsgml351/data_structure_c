#ifndef BINARYTREE_H
#define BINARYTREE_H

// 2진 트리의 구조를 결정
typedef struct _btreeNode {
    int data; // Tree의 Node가 실제로 저장하는 데이터
    struct _btreeNode* leftNode; // 왼쪽 자식 노드
    struct _btreeNode* rightNode; // 오른쪽 자식 노드
} BTreeNode;

#endif //BINARYTREE_H
