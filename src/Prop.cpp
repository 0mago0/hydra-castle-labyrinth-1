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
        clsglobal::bricks_x.erase(clsglobal::bricks_x.begin()+number);
        clsglobal::bricks_y.erase(clsglobal::bricks_y.begin()+number);
        SetPosition({GetPosition()[0],GetPosition()[1]+30});
        HP = 1000 ;
        SetImage({RESOURCE_DIR"/Prop/Prop_hp.png"},10,false);
    }
}
void Prop::move_even() {

}


