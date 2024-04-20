//
// Created by Yihss on 2024/4/20.
//

#include "caterpillar.hpp"
caterpillar::caterpillar() {
    //m_ZIndex = -1 ;
    if(forward == "R"){
        SetImage(Rpath,150,true) ;
    }else{
        SetImage(Lpath,150,true) ;
    }
    HP = 2 ;
    //  SetPosition({0,-60}) ;
    state = "on_ground" ;
}
void caterpillar::move_even() {
    if(forward == "R"){
        SetPosition({GetPosition()[0] +1 , GetPosition()[1]}) ;
        move_total += 1 ;
    }else{
        SetPosition({GetPosition()[0] - 1, GetPosition()[1]}) ;
        move_total +=1;
    }
    if(move_total >= 120){
        if(forward == "R"){
            SetImage(Lpath,150,true) ;
            move_total = 0 ;
            this->forward = "L" ;
        }else{
            SetImage(Rpath,150,true) ;
            move_total = 0;
            this-> forward = "R" ;
        }
    }
}
void caterpillar::attack(const glm::vec2& hero_position) {

}
