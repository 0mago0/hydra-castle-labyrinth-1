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
            auto temp = std::dynamic_pointer_cast<Util::GameObject>(slime) ;
            all_enemy.push_back(slime) ;
            m_Root.AddChild(temp) ;

        }
    }
    ifs.close();

}