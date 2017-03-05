//
//  chess_algorithm.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/5/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"

struct Point {
    int x;
    int y;
};

bool pointIsExists(vector<Point> vp, Point p) {
    
    int len = (int)vp.size();
    
    for(int i = 0; i < len; ++i) {
        if(vp[i].x == p.x && vp[i].y == p.y)
            return true;
    }
    
    return false;
}

void findTheWayHorseFromAtoB_v1() {
    Point start, end;
    start.x = 1;
    start.y = 1;
    
    end.x = 7;
    end.y = 6;
    
    Point nextPoint[8];
    nextPoint[0].y = 2;
    nextPoint[0].x = 1;
    
    nextPoint[1].y = 1;
    nextPoint[1].x = 2;
    
    nextPoint[2].y = -1;
    nextPoint[2].x = 2;
    
    nextPoint[3].y = -2;
    nextPoint[3].x = 1;
    
    nextPoint[4].y = -2;
    nextPoint[4].x = -1;
    
    nextPoint[5].y = -1;
    nextPoint[5].x = -2;
    
    nextPoint[6].y = 1;
    nextPoint[6].x = -2;
    
    nextPoint[7].y = 2;
    nextPoint[7].x = -1;
    
    // run DFS
    vector<Point> tracking;
    
    stack<Point> stackVers;
    stackVers.push(start);
    
    cout << "List step of horse: " << endl;
    
    while(!stackVers.empty()) {
        Point currentPoint = stackVers.top();
        tracking.push_back(currentPoint);
        
        cout << "x = " << currentPoint.x << " --- y = " << currentPoint.y << endl;
        
        if(currentPoint.x == end.x && currentPoint.y == end.y)
            break;
        
        for(int i = 0; i < 7; ++i) {
            Point desPoint;
            desPoint.x = currentPoint.x + nextPoint[i].x;
            desPoint.y = currentPoint.y + nextPoint[i].y;
            
            if(desPoint.x > 7 || desPoint.x < 0 || desPoint.y > 7 || desPoint.y < 0)
                continue;
            
            if(pointIsExists(tracking, desPoint))
                continue;
            
            stackVers.push(desPoint);
            break;
        }
    }
    
    cout << "End!!!!!!! " << endl << endl;
}
