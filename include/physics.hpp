//
// Created by Yihss on 2024/3/2.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_PHYSICS_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_PHYSICS_HPP
#include "Util/GameObject.hpp"
#include "map.hpp"
class physics {
public:
    void in_sky_down();
    void set_data(const std::string& dataPath);
    std::vector<glm::vec2> object_position ;
private :
    int data[16][12];
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_PHYSICS_HPP
