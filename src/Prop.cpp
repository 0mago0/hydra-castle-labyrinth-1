//
// Created by Yihss on 2024/5/10.
//

#include "Prop.hpp"
#include <fstream>
#include <iostream>

const std::vector<std::string> Prop::split(const std::string &str, const std::string &pattern) {
        std::vector<std::string> result;
        std::string::size_type begin, end;
        end = str.find(pattern);
        begin = 0;

        while (end != std::string::npos) {
            if (end - begin != 0) {
                result.push_back(str.substr(begin, end-begin));
            }
            begin = end + pattern.size();
            end = str.find(pattern, begin);
        }

        if (begin != str.length()) {
            result.push_back(str.substr(begin));
        }
        return result;
}

Prop::Prop() {
    m_ZIndex =21 ;
    enemy_name = "prob";
    state = "on_ground" ;
    SetImage({RESOURCE_DIR"/Prop/Prop_bricks.png"},10,false);
    HP = 2 ;
}

void Prop::attack(std::shared_ptr<hero> m_hero) {
    if(HP == 1){
        clsglobal::bricks_number[number] = 0 ;
        SetPosition({GetPosition()[0],GetPosition()[1]+30});
        HP = 1000 ;
        if(treasure == "hp"){
            SetImage({RESOURCE_DIR"/Prop/Prop_hp.png"},10,false);

        }
        if(treasure == "key1"){
            SetImage({RESOURCE_DIR"/Prop/Prop_key.png"},10,false);
        }
        if(treasure == "key2"){
            SetImage({RESOURCE_DIR"/Prop/Prop_key2.png"},10,false);
        }
        if(treasure == "key3"){
            SetImage({RESOURCE_DIR"/Prop/Prop_key3.png"},10,false);
        }
        if(treasure == "boots"){
            SetImage({RESOURCE_DIR"/Prop/Prob_boots.png"},10,false);
        }
    }
    if(HP > 500 ){
        float x1,y1,x2,y2,x,y,distance ;
        x1 = m_hero->GetPosition()[0] ;
        y1 = m_hero->GetPosition()[1] ;
        x2 = GetPosition()[0] ;
        y2 = GetPosition()[1] ;
        x = x1-x2 ;
        y = y1-y2 ;
        distance = sqrt(x*x + y*y) ;

        if(distance < 30 && m_hero->HP > 0 && m_hero->nocontrol == false){
            if(treasure == "hp"){
                if(m_hero->HP < 20){
                    m_hero->HP = m_hero->HP + 1 ;
                }
            }
            if(treasure == "key"){
                m_hero->key1 = true ;
            }
            if(treasure == "key2") {
                m_hero->key2 = true ;
            }
            if(treasure == "key3"){
                m_hero->key3 = true ;
            }
            if(treasure == "boots"){
                m_hero->two_jump_shoes = true ;
            }
            m_Visible = false ;
            SetPosition({-1000,-1000});
        }
    }
}
void Prop::move_even() {

}


