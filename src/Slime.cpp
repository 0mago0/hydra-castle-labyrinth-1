//
// Created by a2685 on 2024/4/12.
//

#include "Slime.hpp"
Slime::Slime() {
    //m_ZIndex = -1 ;
    SetImage(path) ;
    SetPosition({0,0}) ;
    state = "sky_down" ;
}
void Slime::jump() {
    SetPosition({GetPosition()[0] , GetPosition()[1] + 5 }) ;
}
void Slime::move_even() {

}
void Slime::attack() {

}