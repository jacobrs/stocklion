#include "VectorComparator.h"

bool VectorComparator::comparePositions(std::vector<Position> p1, std::vector<Position> p2) {
    if(p1.size() != p2.size()){
        return false;
    }

    for(int i = 0; i < p1.size(); i++){
        if(p1[i] != p2[i]){
            return false;
        }
    }
    return true;
}
