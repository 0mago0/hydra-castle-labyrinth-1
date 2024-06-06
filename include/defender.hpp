//
// Created by Yihss on 2024/6/7.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_DEFENDER_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_DEFENDER_HPP
#include "enemy.hpp"
#include "enemy.hpp"
#include "physics.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
class defender : public enemy{
public:
    explicit defender() ;
    void move_even() override ;
    void attack(std::shared_ptr<hero> m_hero) override ;
protected:
    float move_total = 0;
    bool jp = false ,aleardy = false;

    std::string forward = "R" ;
    std::vector<std::string> Rpath = {RESOURCE_DIR"/enemy/Rdefinder1.png",RESOURCE_DIR"/enemy/Rdefinder2.png"} ;
    std::vector<std::string> Lpath = {RESOURCE_DIR"/enemy/Ldefinder1.png",RESOURCE_DIR"/enemy/Ldefinder2.png"} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_DEFENDER_HPP
