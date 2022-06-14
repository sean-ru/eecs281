#include <iostream>
#include <vector>
class Solution {
public:
    bool carPooling(std::vector<std::vector<int> >& trips, int capacity) {
        int numTrips = trips.size();
        int numPassengers = 0;
        std::vector<std::pair<int, int> > pickup;
        std::vector<std::pair<int, int> > dropoff;
        
        std::vector<int> pickupSpots;
        std::vector<int> dropoffSpots;
        
        for (int i = 0; i < numTrips; ++i) {
            pickup.push_back(std::make_pair(trips[i][1], trips[i][0]));
            dropoff.push_back(std::make_pair(trips[i][2], trips[i][0]));
        }
        for (int i = 0; i < pickup.size(); ++i) {
            pickupSpots.push_back(pickup[i].first);
            dropoffSpots.push_back(dropoff[i].first);
        }
        
        sort(pickupSpots.begin(), pickupSpots.end());
        sort(dropoffSpots.begin(), dropoffSpots.end());
        int maximum = std::max(pickupSpots[numTrips - 1], dropoffSpots[numTrips - 1]);
        
        for (int i = 0; i < maximum; ++i) {
            for (int j = 0; j < pickup.size(); ++j) {
                if (i == pickup[j].first) {
                    numPassengers += pickup[j].second;
                }
            }
            for (int k = 0; k < dropoff.size(); ++k) {
                if (i == dropoff[k].first) {
                    numPassengers -= dropoff[k].second;
                }
            }
            if (numPassengers > capacity) {
                return false;
            }
        }
        return true;
    }
};