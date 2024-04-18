//
// Created by Yihss on 2024/4/19.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_GENERATE_ENEMY_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_GENERATE_ENEMY_HPP
#include <string>
#include <vector>
#include "Util/GameObject.hpp"
#include "Util/Root.hpp"
#include "hero.hpp"
#include "Slime.hpp"
#include "enemy.hpp"
#include <fstream>
#include <iostream>

class generate_enemy {
public:

    void setpath(const std::string& dataPath);
    void generat(Util::Root &m_Root,std::vector<std::shared_ptr<enemy>> &all_enemy) ;
private:
    std::string path ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_GENERATE_ENEMY_HPP
