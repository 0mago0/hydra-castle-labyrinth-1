//
// Created by Yihss on 2024/3/2.
//

#include "physics.hpp"
std::string physics::get_state() {
    for(size_t i = 0 ; i < state.size() ; i++){
        return state[i] ;
    }
}
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

void  physics::in_sky_down() {

    for(size_t i = 0 ; i < object_position.size() ; i++){
        float yy =6*60 - (ceil(object_position[i][1]) - 25 );
        float y = 6*60 - object_position[i][1] -30    ; //60 is hero height
        float  x = 8 * 60 + object_position[i][0] - 30 ;
        float  Lx = 8 * 60 + object_position[i][0] - 60  ;
        yy = ceil(yy)  / 60 ;
        y = ceil(y  / 60) ;
        x = ceil(x / 60) ;
        Lx = ceil(Lx / 60) ;
        if (data[int(x)][int(yy)] == 1){
x -= 4.5 ;
            object_position[i][0] = object_position[i][0] - 4 ;

        }
        if (data[int(Lx)][int(yy)] == 1){
x+= 4.5 ;
            object_position[i][0] = object_position[i][0] + 4 ;
        }
        x = 8 * 60 + object_position[i][0] - 30 ;
        x = ceil(x / 60) ;
        Lx = 8 * 60 + object_position[i][0] - 60 ;
        Lx = ceil(Lx / 60) ;
        if(ceil(yy) - yy <= 0.2){
            yy = ceil(yy);
        }
        if (data[int(x)][int(y)] <= 0 && data[int(Lx)][int(y)] <= 0  && state[i] =="sky_down"  ){
            object_position[i][1] = object_position[i][1] - 0.3 * jump_total[i] ;
            jump_total[i] +=1 ;
        } else if(data[int(x)][int(y)] > 0 && data[int(Lx)][int(y)] > 0 &&  state[i] != "on_ground" ) {
            jump_total.clear();
            object_position[i][1] = 360 - (y) * 60 + 30;
            jump_total[i] = 0 ;
            state[i] = "on_ground" ;

        }else if(data[int(x)][int(yy)] <= 0 && data[int(Lx)][int(yy)] <= 0 && state[i] =="on_ground"){
            state[i] ="sky_down";

        }
        object_position.clear();
    }

}