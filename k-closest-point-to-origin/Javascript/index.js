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

var kClosest = function(points, k) {
    const heap = [];
    const distance = (p) => p[0] * p[0] + p[1] * p[1];
    const swap = (i, j) => {
        [heap[i], heap[j]] = [heap[j], heap[i]];
    };

    const heapifyUp = (index) => {
        while (index > 0) {
            let parent = Math.floor((index - 1) / 2);

            if (heap[parent][0] >= heap[index][0]) break;

            swap(parent, index);
            index = parent;
        }
    };

    const heapifyDown = (index) => {
        const size = heap.length;

        while (true) {
            let largest = index;
            let left = index * 2 + 1;
            let right = index * 2 + 2;

            if (left < size && heap[left][0] > heap[largest][0]) {
                largest = left;
            }

            if (right < size && heap[right][0] > heap[largest][0]) {
                largest = right;
            }

            if (largest === index) break;

            swap(index, largest);
            index = largest;
        }
    };

    for (const point of points) {
        const dist = distance(point);

        if (heap.length < k) {
            heap.push([dist, point]);
            heapifyUp(heap.length - 1);
        } else if (dist < heap[0][0]) {
            heap[0] = [dist, point];
            heapifyDown(0);
        }
    }

    return heap.map(item => item[1]);
};