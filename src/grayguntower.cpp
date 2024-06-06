//
// Created by Yihss on 2024/4/24.
//

#include "grayguntower.hpp"
grayguntower::grayguntower(std::string Forward) {
    //m_ZIndex = -1 ;
    this->forward = Forward ;
    if(forward == "R"){
        SetImage(Rpath,150,true,false) ;
    }else{
        SetImage(Lpath,150,true,false) ;
    }
    HP = 2 ;
    //  SetPosition({0,-60}) ;
    state = "" ;
}
void grayguntower::move_even() {

}
void grayguntower::attack(std::shared_ptr<hero> m_hero) {
    float hero_x = m_hero->GetPosition()[0] ;
    float hero_y = m_hero->GetPosition()[1] ;
    float mx,my ;
    mx = GetPosition()[0] ;
    my = GetPosition()[1] ;
    int num = 1 ;
    if(this->forward == "R"){num = -1;}
    if(sqrt((mx-hero_x) *(mx-hero_x) +  (my-hero_y) *(my-hero_y)) < 3000 && distance == 0){
        Ammo->SetPosition({GetPosition()[0]-5*num,GetPosition()[1]});
        distance = 5 ;
        Ammo->play() ;
        ammo_bomb_judge(m_hero->GetPosition()[0] , m_hero->GetPosition()[1] , Ammo->GetPosition()[0],Ammo->GetPosition()[1] , m_hero);
        ammo_bomb_judge(m_hero->GetPosition()[0] , m_hero->GetPosition()[1] , GetPosition()[0],GetPosition()[1] , m_hero);
    }else if(distance <= 970){
        Ammo->SetPosition({Ammo->GetPosition()[0]-5*num,Ammo->GetPosition()[1]});
        distance += 5 ;
        ammo_bomb_judge(m_hero->GetPosition()[0] , m_hero->GetPosition()[1] , Ammo->GetPosition()[0],Ammo->GetPosition()[1] , m_hero);
        ammo_bomb_judge(m_hero->GetPosition()[0] , m_hero->GetPosition()[1] , GetPosition()[0],GetPosition()[1] , m_hero);
    }else{
        distance = 0 ;
    }
}
void grayguntower::ammo_bomb_judge(float h_x,float h_y , float m_x , float m_y,std::shared_ptr<hero> m_hero) {
    float dist = 0 ;
    float x = h_x - m_x ;
    float y = h_y - m_y ;
    dist = sqrt(x*x + y*y) ;
     if(dist < 30 && m_hero->nocontrol == false && !m_hero->Invincible   ){
        m_hero->hero_state = "attacked" ;
        m_hero->HP -= 1 ;
        if (m_x > h_x){
            m_hero->forward = "R" ;
        }else {
            m_hero->forward = "L" ;
        }
    }
}

