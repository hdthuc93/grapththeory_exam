//
//  implement_func.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/1/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "implement_func.hpp"
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

bool isPointExistInQueue(vector<int> v, int element) {
    for(int i = 0; i < v.size(); ++i) {
        if(element == v[i])
            return true;
    }
    
    return false;
}

bool readData(string fileName, int &numOfVertexes, short** &adjacencyMatrix) {
    
    ifstream fileData(fileName, ios::in);
    
    if(fileData.is_open()) {
        fileData >> numOfVertexes;
        
        adjacencyMatrix = new short*[numOfVertexes];
        
        for(int i = 0; i < numOfVertexes; ++i) {
            adjacencyMatrix[i] = new short[numOfVertexes];
            
            for(int j = 0; j < numOfVertexes; ++j) {
                fileData >> adjacencyMatrix[i][j];
            }
        }
        
        fileData.close();
        return true;
    }
    
    return false;
}

void DFS_simple_v1(int local, bool trackingPoint[], int numOfVertexes, short** adjacencyMatrix) {
    trackingPoint[local] = true;
    
    for(int i = 0; i < numOfVertexes; ++i) {
        cout << trackingPoint[i] << " ";
    }
    cout << endl;
    
    
    for(int i = 0; i < numOfVertexes; ++i) {
        if(adjacencyMatrix[local][i] == 1 && !trackingPoint[i]) {
            DFS_simple_v1(i, trackingPoint, numOfVertexes, adjacencyMatrix);
            cout << "Back to point: " << local << endl;
        }
    }
}

void DFS_simple_v2(int numOfVertexes, short** adjacencyMatrix) {
    int startVer = 3;
    int verLabels[numOfVertexes];
    
    for(int i = 0; i < numOfVertexes; ++i) {
        verLabels[i] = 0;
    }
    
    stack<int> stackVers;
    stackVers.push(startVer);
    
    cout << "DFS version 2: ";
    
    while(!stackVers.empty()) {
        int iVerLabel = stackVers.top();
        bool isNotCont = true;
//        if(verLabels[iVerLabel] != 0) {
//            stackVers.pop();
//            continue;
//        }
        
        verLabels[iVerLabel] = 1;
        
        // Print result
        cout << iVerLabel << " ";
        
        for(int i = 0; i < numOfVertexes; ++i) {
            if(adjacencyMatrix[iVerLabel][i] == 1 && verLabels[i] == 0) {
                stackVers.push(i);
                isNotCont = false;
                break;
            }
        }
        
        if(isNotCont) {
            stackVers.pop();
        }
    }
    cout << endl;
    
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



