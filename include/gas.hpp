//
// Created by Yihss on 2024/5/26.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_GAS_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_GAS_HPP
#include "enemy.hpp"
#include "physics.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class gas: public enemy {
public:
    explicit gas() ;
    void move_even() override ;
    void attack(std::shared_ptr<hero> m_hero) override ;
protected:
    float inter = 0;
    bool jp = false ,check_attack = false;
    unsigned long attack_invert = 0 ;
    std::string forward = "R" ;
    std::vector<std::string> path = {RESOURCE_DIR"/enemy/gas1.png",RESOURCE_DIR"/enemy/gas2.png",RESOURCE_DIR"/enemy/gas3.png",RESOURCE_DIR"/enemy/gas4.png",RESOURCE_DIR"/enemy/gas5.png"} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_GAS_HPP
