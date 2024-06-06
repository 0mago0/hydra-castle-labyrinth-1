//
// Created by Yihss on 2024/6/7.
//

#include "defender.hpp"
defender::defender() {
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
void defender::move_even() {
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
void defender::attack(std::shared_ptr<hero> m_hero) {
    float x1,y1,x2,y2,x3,x,y,distance ;
    x1 = m_hero->GetPosition()[0] ;
    y1 = m_hero->GetPosition()[1] ;
    x2 = GetPosition()[0] ;
    y2 = GetPosition()[1] ;
    x = x1-x2 ;
    y = y1-y2 ;
    bool sword_collision = false ;
    distance = sqrt(x*x + y*y) ;
    if(this-> forward == "R"){
        x3 =  GetPosition()[0] + 40 ;
        if(((x1-28 <= x3 && x1-28 >= GetPosition()[0]) ||  (x1+28 <= x3 && x1+28 >= GetPosition()[0])) && abs(y2-y1) < 5 ){
            sword_collision = true  ;
        }
    }
    if(this-> forward == "L"){
        x3 =  GetPosition()[0] - 40 ;
        if(((x1-28 >= x3 && x1-28 <= GetPosition()[0]) ||  (x1+28 >= x3 && x1+28 <= GetPosition()[0]))&& abs(y2-y1) < 5 ){
            sword_collision = true  ;
        }
    }
    if((distance < 50 || sword_collision ) && m_hero->HP > 0 && !m_hero->Invincible){
        m_hero->hero_state = "attacked" ;
        m_hero->HP -= 1 ;
        m_hero->Invincible = true  ;
        if (x2 > x1){
            m_hero->forward = "R" ;
        }else {
            m_hero->forward = "L" ;
        }
    }
}
