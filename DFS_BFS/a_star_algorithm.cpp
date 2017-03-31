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
    short distance[11] = {5, 8, 2, 4, 6, 5, 10, 10, 7, 8, 0};
    
    vector<NODE> notePending;
    NODE start = { 7, 0, distance[7], NULL };
    notePending.push_back(start);
    
    while(true) {
        NODE current = notePending[0];
        int currentIndex = current.index;
        for(int i = 0; i < numOfvers; ++i) {
            if(weighMaxtrix[currentIndex][i] != 0) {
                int vtIndex = getIndexInVector(notePending, i);
                if(vtIndex == -1) {
                    
                }
            }
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
