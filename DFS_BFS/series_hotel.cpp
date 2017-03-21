//
//  series_hotel.cpp
//  DFS_BFS
//
//  Created by ThucHD on 3/21/17.
//  Copyright © 2017 ThucHD. All rights reserved.
//

#include "declare.hpp"

/*
    At Ho Chi Minh city has N hotel with different prices
    I have M money and want to buy series of hotel
    Find MAX series of hotels I can buy it
 */

struct hotelsTarget {
    int headPos, tailPos;
    int nHotel;
    float totalAmount;
    
};

void findMaxSeriesHotels() {
    int priceOfHotel[10] = {20, 30, 10, 100, 4, 6, 9, 50, 20, 2};
    int money = 60;
    
    vector<hotelsTarget> lstTarget;
    hotelsTarget hotels;
    int index = 0;
    
    hotels.nHotel = 0;
    
    while(index < 10) {
        if(hotels.nHotel == 0) {
            if(priceOfHotel[index] > money) {
                ++index;
            } else {
                hotels.headPos = index;
                hotels.tailPos = index;
                hotels.totalAmount = priceOfHotel[index];
                ++hotels.nHotel;
                ++index;
            }
            continue;
        }
        
        int amount = hotels.totalAmount + priceOfHotel[index];
        
        if(amount > money) {
            lstTarget.push_back(hotels);
            index = hotels.headPos + 1;
            hotels.nHotel = 0;
            continue;
        }
        
        hotels.tailPos = index;
        hotels.totalAmount = amount;
        ++hotels.nHotel;
        ++index;
    }
    
    if(hotels.nHotel > 0)
        lstTarget.push_back(hotels);
    
    if(lstTarget.empty()) {
        cout << "Not enough money for any hotels" << endl;
        return;
    }
    
    int maxSeries = lstTarget[0].nHotel;
    
    for(int i = 1; i < lstTarget.size(); ++i) {
        if(maxSeries < lstTarget[i].nHotel)
            maxSeries = lstTarget[i].nHotel;
    }
    
    for(int i = 0; i < lstTarget.size(); ++i) {
        if(maxSeries == lstTarget[i].nHotel) {
            cout << "Series of hotel can buy: " << lstTarget[i].headPos << " -> " << lstTarget[i].tailPos << endl;
            cout << "Amount of money: " << lstTarget[i].totalAmount << endl;
        }
        
    }
    
    
    
    
}
