//
// Created by Yihss on 2024/6/9.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_BIRD_BOSS_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_BIRD_BOSS_HPP
#include "enemy.hpp"
#include "enemy.hpp"
#include "physics.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
class bird_boss: public  enemy{
public:
    explicit bird_boss() ;
    void move_even() override ;
    void attack(std::shared_ptr<hero> m_hero) override ;
    std::string bird_state = "stay" ;
protected:
    float move_total = 0;
    int Lindex = 0 ,Rindex = 0 ;
    bool jp = false ,aleardy = false;

    std::string forward = "R" ;
    std::vector<std::string> Rpath = {RESOURCE_DIR"/enemy/Lboss1.png",RESOURCE_DIR"/enemy/Lboss2.png",RESOURCE_DIR"/enemy/Lboss3.png",RESOURCE_DIR"/enemy/Lboss4.png",RESOURCE_DIR"/enemy/Lboss5.png",RESOURCE_DIR"/enemy/Lboss6.png"} ;
    std::vector<std::string> Lpath = {RESOURCE_DIR"/enemy/Rboss1.png",RESOURCE_DIR"/enemy/Rboss2.png",RESOURCE_DIR"/enemy/Rboss3.png",RESOURCE_DIR"/enemy/Rboss4.png",RESOURCE_DIR"/enemy/Rboss5.png",RESOURCE_DIR"/enemy/Rboss6.png"} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_BIRD_BOSS_HPP
