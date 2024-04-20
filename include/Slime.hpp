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
    void attack(std::shared_ptr<hero> m_hero) override ;
protected:
    float jump_total = 0;
    bool jp = false ,aleardy = false;
    std::vector<std::string> path = {RESOURCE_DIR"/enemy/slime1.png",RESOURCE_DIR"/enemy/slime2.png",RESOURCE_DIR"/enemy/slime3.png",RESOURCE_DIR"/enemy/slime4.png",RESOURCE_DIR"/enemy/slime5.png",RESOURCE_DIR"/enemy/slime6.png",RESOURCE_DIR"/enemy/slime7.png"} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_SLIME_HPP
