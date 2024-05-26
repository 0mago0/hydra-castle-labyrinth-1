//
// Created by Yihss on 2024/4/19.
//

#include "generate_enemy.hpp"
const std::vector<std::string> split(const std::string& str, const std::string& pattern) {
    std::vector<std::string> result;
    std::string::size_type begin, end;
    end = str.find(pattern);
    begin = 0;

    while (end != std::string::npos) {
        if (end - begin != 0) {
            result.push_back(str.substr(begin, end-begin));
        }
        begin = end + pattern.size();
        end = str.find(pattern, begin);
    }

    if (begin != str.length()) {
        result.push_back(str.substr(begin));
    }
    return result;
}

void generate_enemy::setpath(const std::string& dataPath){
    this ->path = RESOURCE_DIR"/enemy_data/" + dataPath ;
}
void generate_enemy:: generat(Util::Root &m_Root,std::vector<std::shared_ptr<enemy>> &all_enemy) {
    std::ifstream ifs(this ->path, std::ios::in);
    std::string s;
    while (std::getline(ifs, s)) {
        std::vector<std::string> data = split(s, " ");
        if(data[0] == "slime"){
            std::shared_ptr<Slime> slime = std::make_shared<Slime>() ;

            slime->SetPosition({std::stof(data[1]),std::stof(data[2])});
            slime->m_miscellaneous = std::make_shared<miscellaneous>("attack_miscellaneous");

            auto temp = std::dynamic_pointer_cast<Util::GameObject>(slime) ;
            temp->AddChild(slime->m_miscellaneous );

            all_enemy.push_back(slime) ;
            m_Root.AddChild(temp) ;
        }
        if(data[0] == "caterpillar"){
            std::shared_ptr<caterpillar> Caterpillar = std::make_shared<caterpillar>() ;
            Caterpillar->SetPosition({std::stof(data[1]),std::stof(data[2])});
            Caterpillar->m_miscellaneous = std::make_shared<miscellaneous>("attack_miscellaneous");
            auto temp = std::dynamic_pointer_cast<Util::GameObject>(Caterpillar) ;
            temp->AddChild(Caterpillar->m_miscellaneous );
            all_enemy.push_back(Caterpillar) ;
            m_Root.AddChild(temp) ;
        }
        if(data[0] == "grayguntower"){
            std::shared_ptr<grayguntower> Grayguntower = std::make_shared<grayguntower>(data[3])   ;
            Grayguntower->SetPosition({std::stof(data[1]),std::stof(data[2])});
            Grayguntower->m_miscellaneous = std::make_shared<miscellaneous>("attack_miscellaneous");
            auto temp = std::dynamic_pointer_cast<Util::GameObject>(Grayguntower) ;
            Grayguntower->Ammo->SetPosition({std::stof(data[1]),std::stof(data[2])});
            temp->AddChild(Grayguntower->Ammo);
            temp->AddChild(Grayguntower->m_miscellaneous );
            all_enemy.push_back(Grayguntower) ;
            m_Root.AddChild(temp) ;
        }
        if(data[0] == "prob"){
            std::shared_ptr<Prop> prob = std::make_shared<Prop>() ;
            prob->number = std::stoi(data[5]) - 1 ;
            clsglobal::bricks_number.push_back(prob->number);
            clsglobal::bricks_x.push_back(std::stoi(data[3]));
            clsglobal::bricks_y.push_back(std::stoi(data[4]));
            prob->SetPosition({std::stof(data[1]),std::stof(data[2])});
            prob->m_miscellaneous = std::make_shared<miscellaneous>("attack_miscellaneous");
            std::vector<std::string> ss = split(this ->path, "enemy");
            ss =  split(ss[ss.size()-1], ".txt");
            prob->map_number =std::stoi(ss[0]);
            auto temp = std::dynamic_pointer_cast<Util::GameObject>(prob) ;
            temp->AddChild(prob->m_miscellaneous );
            all_enemy.push_back(prob) ;
            m_Root.AddChild(temp) ;
        }
        if(data[0] == "gas"){
            std::shared_ptr<gas> Gas = std::make_shared<gas>() ;
            Gas->SetPosition({std::stof(data[1]),std::stof(data[2])});
            Gas->m_miscellaneous = std::make_shared<miscellaneous>("attack_miscellaneous");
            auto temp = std::dynamic_pointer_cast<Util::GameObject>(Gas) ;
            temp->AddChild(Gas->m_miscellaneous );
            all_enemy.push_back(Gas) ;
            m_Root.AddChild(temp) ;
        }
    }
    ifs.close();

}