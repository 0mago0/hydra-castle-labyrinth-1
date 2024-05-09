//
// Created by Yihss on 2024/4/20.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_CATERPILLAR_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_CATERPILLAR_HPP
#include "enemy.hpp"
#include "physics.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class caterpillar: public enemy {
public:
    explicit caterpillar() ;
    void move_even() override ;
    void attack(std::shared_ptr<hero> m_hero) override ;
protected:
    float move_total = 0;
    bool jp = false ,aleardy = false;

    std::string forward = "R" ;
    std::vector<std::string> Rpath = {RESOURCE_DIR"/enemy/Rcaterpillar1.png",RESOURCE_DIR"/enemy/Rcaterpillar2.png",RESOURCE_DIR"/enemy/Rcaterpillar3.png"} ;
    std::vector<std::string> Lpath = {RESOURCE_DIR"/enemy/Lcaterpillar1.png",RESOURCE_DIR"/enemy/Lcaterpillar2.png",RESOURCE_DIR"/enemy/Lcaterpillar3.png"} ;

};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_CATERPILLAR_HPP
