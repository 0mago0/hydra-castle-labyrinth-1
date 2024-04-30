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
    state = "on_ground" ;
}
void grayguntower::move_even() {

}
void grayguntower::attack(std::shared_ptr<hero> m_hero) {
    float hero_x = m_hero->GetPosition()[0] ;
    float hero_y = m_hero->GetPosition()[1] ;
    float mx,my ;
    mx = GetPosition()[0] ;
    my = GetPosition()[1] ;

    if(sqrt((mx-hero_x) *(mx-hero_x) +  (my-hero_y) *(my-hero_y)) < 300 && distance == 0){
        Ammo->SetPosition({GetPosition()[0]-5,GetPosition()[1]});
        distance = 5 ;
        Ammo->play() ;
    }else if(distance <= 600){
        Ammo->SetPosition({Ammo->GetPosition()[0]-5,Ammo->GetPosition()[1]});
        distance += 5 ;
    }else{
        distance = 0 ;
    }


}

