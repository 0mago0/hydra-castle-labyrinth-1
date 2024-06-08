//
// Created by Yihss on 2024/6/9.
//

#include "bird_boss.hpp"
//
// Created by Yihss on 2024/4/20.
//

bird_boss::bird_boss() {
    //m_ZIndex = -1 ;
    bird_state = "stay" ;
    if(forward == "R"){
        SetImage(Rpath,250,true) ;
    }else{
        SetImage(Lpath,250,true) ;
    }
    HP = 50 ;
    //  SetPosition({0,-60}) ;
    state = "on_ground" ;
}
void bird_boss::move_even() {
    if(bird_state == "stay"){
        Lindex = 0 ;
        Rindex = 3 ;
        if(forward == "R"){

        }else{

        }
    }

}
void bird_boss::attack(std::shared_ptr<hero> m_hero) {
    float x1,y1,x2,y2,x,y,distance ;
    x1 = m_hero->GetPosition()[0] ;
    y1 = m_hero->GetPosition()[1] ;
    x2 = GetPosition()[0] ;
    y2 = GetPosition()[1] ;
    x = x1-x2 ;
    y = y1-y2 ;
    distance = sqrt(x*x + y*y) ;
    if(distance < 70 && m_hero->HP > 0 && !m_hero->Invincible){
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
