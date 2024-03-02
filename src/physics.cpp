//
// Created by Yihss on 2024/3/2.
//

#include "physics.hpp"
void  physics::set_data(const std::string& dataPath){
    std::ifstream inputfile(RESOURCE_DIR"/map_data/" + dataPath);
    for(int y =0;y<12;y++)
    {
        for(int x=0;x<16;x++)
        {
            inputfile >> data[x][y];
        }
    }
}
void physics::in_sky_down() {
    for(size_t i = 0 ; i < object_position.size() ; i++){

        float y = 6*60 - object_position[i][1] -30    ; //60 is hero height
        float  x = 8 * 60 + object_position[i][0] - 30 ;
        float  Lx = 8 * 60 + object_position[i][0] - 60  ;
        y = ceil(y / 60) ;
        x = ceil(x / 60) ;
        Lx = ceil(Lx / 60) ;
        if (data[int(x)][int(y)] <= 0 && data[int(Lx)][int(y)] <= 0){
            object_position[i][1] = object_position[i][1] - 4 ;
        }
    }
    object_position.clear() ;
}