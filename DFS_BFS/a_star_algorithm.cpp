//
//  a_star_algorithm.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/31/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"

struct NODE {
    int index;
    int d; // distance
    int h; // heuristic
    NODE* prevNode;
};

void quickSort(vector<NODE> &vt, int first, int last);
int getIndexInVector(vector<NODE> vt, int nodeIndex);

void a_star(int numOfvers, short** weighMaxtrix) {
    // List star node: 7, 8, 9
    // End node: 10
    
    // distance each node to end node
    short distance[11] = { 5, 8, 2, 4, 6, 5, 10, 10, 7, 8, 0 };
//    short distance[8] = { 15, 8, 7, 9, 1, 2, 3, 0 };
    
    //
    bool* isExist = new bool[numOfvers];
    for(int i = 0; i < numOfvers; ++i) {
        isExist[i] = false;
    }
    
    // lambda
//    auto cmp = [](NODE left, NODE right) { return left.h < right.h; };
//    std::priority_queue<NODE, vector<NODE>, decltype(cmp)> nodePending(cmp);
    
    vector<NODE> nodePending;
    queue<NODE> result;
    bool isNext = false;
    NODE start = { 0, 0, distance[0], NULL };
    nodePending.push_back(start);
    NODE current;
    int endNode = -1;
    
    while(true) {
        
        endNode = getIndexInVector(nodePending, 10);
        
        if(endNode != -1) {
            result.push(nodePending[endNode]);
            break;
        }
        
        current = nodePending[0];
        result.push(current);
        nodePending.erase(nodePending.begin());
        int currentIndex = current.index;
        isExist[currentIndex] = true;
        for(int i = 0; i < numOfvers; ++i) {
            if(weighMaxtrix[currentIndex][i] != 0 && !isExist[i]) {
                isNext = true;
                NODE next;
                next.index = i;
                next.d = current.d + weighMaxtrix[currentIndex][i];
                next.h = next.d + distance[i];
                next.prevNode = &result.back();
                
                int vtIndex = getIndexInVector(nodePending, i);
                
                if(vtIndex == -1) {
                    nodePending.push_back(next);
                } else {
                    NODE existNode = nodePending[vtIndex];
                    
                    if(next.d < existNode.d)
                        nodePending[vtIndex] = next;
                    
                }
            }
        }
        
        if(!isNext)
            break;
        
        isNext = false;
        quickSort(nodePending, 0, (int)nodePending.size() - 1);
    }
    
    
    // show result
    
    if(endNode != -1) {
        NODE* temp = &result.back();

        while(temp != NULL) {
            cout << "Index: " << temp -> index << endl;
            temp = temp -> prevNode;
        }
    }
        
}

void quickSort(vector<NODE> &vt, int first, int last) {
    int len = last - first + 1;
    if(len < 2) {
        return;
    }
    
    NODE p = vt[last];
    int i = first;
    int iGreater = -1;
    
    while(i < last) {
        if(vt[i].h >= p.h) {
            if(iGreater == -1) {
                iGreater = i;
                
            }
        } else {
            if(iGreater != -1) {
                NODE temp = vt[i];
                vt[i] = vt[iGreater];
                vt[iGreater] = temp;
                i = iGreater;
                iGreater = -1;
            }
        }
        i++;
    }
    
    int pIndex;
    if(iGreater != -1) {
        pIndex = iGreater;
        NODE temp = vt[last];
        vt[last] = vt[iGreater];
        vt[iGreater] = temp;
    } else {
        pIndex = last;
    }
    
    quickSort(vt, first, pIndex - 1);
    quickSort(vt, pIndex + 1, last);
}

int getIndexInVector(vector<NODE> vt, int nodeIndex) {
    
    int size = (int)vt.size();
    int index = -1;
    
    for(int i = 0; i < size; ++i) {
        if(vt[i].index == nodeIndex)
            index = i;
    }
    
    return index;
}
