//
// Created by Yihss on 2024/5/26.
//

#include "gas.hpp"
gas::gas() {
    SetImage(path,80,true) ;
    HP = 1000 ;
    //  SetPosition({0,-60}) ;
    state = "on_ground" ;
    inter =  Util::Time::GetElapsedTimeMs();
}

void gas::move_even() {
    unsigned  int sa = Util::Time::GetElapsedTimeMs() -3000 ;
    if(inter < sa){
        inter = Util::Time::GetElapsedTimeMs();
        check_attack = !check_attack ;
    }
    if(check_attack){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        if(temp->GetCurrentFrameIndex() < 2){
            temp->SetCurrentFrame(2);
        }
    }else{
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        if(temp->GetCurrentFrameIndex() >= 2){
            temp->SetCurrentFrame(0);
        }
    }
}

void gas::attack(std::shared_ptr<hero> m_hero) {
    float x1,y1,x2,y2,x,y,distance ;
    x1 = m_hero->GetPosition()[0] ;
    y1 = m_hero->GetPosition()[1] ;
    x2 = GetPosition()[0] ;
    y2 = GetPosition()[1] ;
    x = x1-x2 ;
    y = y1-y2 ;
    distance = sqrt(x*x + y*y) ;
    if(distance < 30 && m_hero->HP > 0 && m_hero->nocontrol == false && check_attack){
        m_hero->hero_state = "attacked" ;
        m_hero->HP -= 1 ;
        if (x2 > x1){
            m_hero->forward = "R" ;
        }else {
            m_hero->forward = "L" ;
        }
    }
}