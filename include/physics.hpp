//
// Created by Yihss on 2024/3/2.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_PHYSICS_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_PHYSICS_HPP
#include "Util/GameObject.hpp"
#include "map.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "clsglobal.hpp"

class physics {
public:

    void in_sky_down();
    void set_data(const std::string& dataPath);
    void collision(int index, float &x , float Lx ,  float yy , float &y) ;
    bool climb_ladder(float x , float y) ;
    bool judge_onground(float x , float y,float topy) ;
    bool enter_boss(float x , float y ) ;
    std::string get_state(int index);
    std::vector<std::string> state ;
    std::vector<glm::vec2> object_position ;
    std::vector<float> jump_total ;
    int data[16][13];
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_PHYSICS_HPP
