//
// Created by Yihss on 2024/5/10.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_PROP_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_PROP_HPP
#include "enemy.hpp"
#include "physics.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Prop: public enemy{
public:
    explicit Prop() ;
    void attack(std::shared_ptr<hero> m_hero) override ;
    void move_even() override ;
    const std::vector<std::string> split(const std::string& str, const std::string& pattern) ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_PROP_HPP
