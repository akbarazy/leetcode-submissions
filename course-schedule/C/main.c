/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1
Input: 
    numCourses = 2
    prerequisites = [[1,0]]
Output: true
Explanation: 
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2
Input: 
    numCourses = 2
    prerequisites = [[1,0],[0,1]]
Output: false
Explanation: 
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** graph = (int**)malloc(sizeof(int*) * numCourses);
    int* graphSize = (int*)calloc(numCourses, sizeof(int));
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(sizeof(int) * prerequisitesSize);
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        graph[prereq][graphSize[prereq]++] = course;
        indegree[course]++;
    }

    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int completed = 0;

    while (front < rear) {
        int current = queue[front++];
        completed++;

        for (int i = 0; i < graphSize[current]; i++) {
            int next = graph[current][i];

            indegree[next]--;

            if (indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    for (int i = 0; i < numCourses; i++) {
        free(graph[i]);
    }

    free(graph);
    free(graphSize);
    free(indegree);
    free(queue);

    return completed == numCourses;
}