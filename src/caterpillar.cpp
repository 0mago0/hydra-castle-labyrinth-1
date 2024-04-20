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
void caterpillar::attack(std::shared_ptr<hero> m_hero) {
    float x1,y1,x2,y2,x,y,distance ;
    x1 = m_hero->GetPosition()[0] ;
    y1 = m_hero->GetPosition()[1] ;
    x2 = GetPosition()[0] ;
    y2 = GetPosition()[1] ;
    x = x1-x2 ;
    y = y1-y2 ;
    distance = sqrt(x*x + y*y) ;
    if(distance < 30){
        m_hero->hero_state = "attacked" ;
        if (x2 > x1){
            m_hero->forward = "R" ;
        }else {
            m_hero->forward = "L" ;
        }
    }
}
