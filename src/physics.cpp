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
void physics::collision(int index,float &x , float Lx ,  float yy , float &y){
    if (data[int(x)][int(yy)] == 1){
        x -= 4.5 ;
        object_position[index][0] = object_position[index][0] - 4 ;
    }
    if (data[int(Lx)][int(yy)] == 1){
        x+= 4.5 ;
        object_position[index][0] = object_position[index][0] + 4 ;
    }

    float  yx = 8 * 60 + object_position[index][0] ;
    float  yLx = 8 * 60 + object_position[index][0] - 30  ;
    yx = ceil(yx / 60) ;
    yLx = ceil(yLx / 60) ;
    if (data[int(yx-1)][int(yy-1)] == 1){
       // y -= 8.5 ;
           object_position[index][1] = object_position[index][1] - 8 ;
    }else if (data[int(yLx)][int(yy-1)] == 1){
       // y -= 8.5 ;
        object_position[index][1] = object_position[index][1] - 8 ;
    }
}
void  physics::in_sky_down() {
    for(size_t i = 0 ; i < object_position.size() ; i++){
        float yy =6*60 - (ceil(object_position[i][1]) - 25 );
        //float top_y = 6*60 - (ceil(object_position[i][1]) + 32 );
        float y = 6*60 - object_position[i][1] -30    ; //60 is hero height
        float  x = 8 * 60 + object_position[i][0] - 30 ;
        float  Lx = 8 * 60 + object_position[i][0] - 60  ;
        yy = ceil(yy)  / 60 ;
       // top_y = ceil(top_y)  / 60 ;
        y = ceil(y  / 60) ;
        x = ceil(x / 60) ;
        Lx = ceil(Lx / 60) ;
        collision(int(i),x,Lx,yy , y) ;
        x = 8 * 60 + object_position[i][0] - 30 ;
        x = ceil(x / 60) ;
        Lx = 8 * 60 + object_position[i][0] - 60 ;
        Lx = ceil(Lx / 60) ;
        if(ceil(yy) - yy <= 0.2){
            yy = ceil(yy);
        }
        if (data[int(x)][int(y)] <= 0 && data[int(Lx)][int(y)] <= 0  && state[i] =="sky_down"  ){
            object_position[i][1] = object_position[i][1] - 0.03 *  (jump_total[i] +2)*  (jump_total[i] +2)* 0.6  ;
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