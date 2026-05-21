/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1
Input: 
    points = [[1,3],[-2,2]]
    k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10). The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin. We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2
Input: 
    points = [[3,3],[5,-1],[-2,4]]
    k = 2
Output: [[3,3],[-2,4]]
Explanation: 
The answer [[-2,4],[3,3]] would also be accepted.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dist;
    int x;
    int y;
} Node;

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Node heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent].dist >= heap[index].dist)
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(Node heap[], int size, int index) {
    while (1) {
        int largest = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (left < size && heap[left].dist > heap[largest].dist)
            largest = left;

        if (right < size && heap[right].dist > heap[largest].dist)
            largest = right;

        if (largest == index)
            break;

        swap(&heap[index], &heap[largest]);
        index = largest;
    }
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    Node* heap = (Node*)malloc(sizeof(Node) * k);
    int heapSize = 0;

    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x * x + y * y;
        Node node = {dist, x, y};

        if (heapSize < k) {
            heap[heapSize] = node;
            heapifyUp(heap, heapSize);
            heapSize++;
        } else if (dist < heap[0].dist) {
            heap[0] = node;
            heapifyDown(heap, heapSize, 0);
        }
    }

    int** result = (int**)malloc(sizeof(int*) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        result[i] = (int*)malloc(sizeof(int) * 2);

        result[i][0] = heap[i].x;
        result[i][1] = heap[i].y;

        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = k;
    free(heap);

    return result;
}