//
//  bfs.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/5/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"

bool isPointExistInQueue(vector<int> v, int element) {
    for(int i = 0; i < v.size(); ++i) {
        if(element == v[i])
            return true;
    }
    
    return false;
}


void BFS_simple_v1(int numOfVertexes, short** adjacencyMatrix) {
    vector<int> pointsInQueue;
    vector<int> result;
    bool trackingPointBFS[numOfVertexes];
    
    for (int i = 0; i < numOfVertexes; ++i) {
        trackingPointBFS[i] = false;
    }
    
    pointsInQueue.push_back(3);
    
    while(pointsInQueue.size() > 0) {
        int local = pointsInQueue[0];
        pointsInQueue.erase(pointsInQueue.begin());
        trackingPointBFS[local] = true;
        result.push_back(local);
        
        for(int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
        
        for(int i = 0; i < numOfVertexes; ++i) {
            if(adjacencyMatrix[local][i] == 1) {
                if(!trackingPointBFS[i] && !isPointExistInQueue(pointsInQueue, i)) {
                    pointsInQueue.push_back(i);
                }
            }
            
        }
    }
}
