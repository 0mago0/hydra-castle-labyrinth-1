//
// Created by a2685 on 2024/4/12.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_SLIME_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_SLIME_HPP
#include "enemy.hpp"
#include "physics.hpp"

class Slime: public enemy{
public:
    explicit Slime() ;
    void jump() ;
    void move_even() override ;
    void attack() override ;
protected:
    std::vector<std::string> path = {RESOURCE_DIR"/enemy/slime1.png"} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_SLIME_HPP
