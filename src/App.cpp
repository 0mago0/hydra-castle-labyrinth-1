#include "App.hpp"
#include "map.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"


void App::gamestart(){
    LOG_TRACE("gamestart");
    auto startScreen = std::make_shared<Util::GameObject>();
    startScreen->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/app/start_background.png"));
    m_Root.AddChild(startScreen);
    m_Root.Update();
    if (Util::Input::IsKeyDown(Util::Keycode::SPACE)) {
        m_CurrentState = State::START;
        m_Root.RemoveChild(startScreen);
        m_Root.Update();
    }
}

void App::Start() {
    LOG_TRACE("Start");

    m_bgm = std::make_shared<Util::BGM>(RESOURCE_DIR"/bgm/Main_01.mp3");
    m_bgm->SetVolume(5);
    m_bgm->Play();
    generate_enemy.setpath("enemy3.txt");
    m_hero = std::make_shared<hero>(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png",RESOURCE_DIR"/hero/Rrun.png",RESOURCE_DIR"/hero/Rrun.png"});
    m_hero->SetPosition({0,-30});
    m_hero->hero_state = "on_ground" ;
    m_Root.AddChild(m_hero);
    phy.set_data("map3.txt");
    m_hero->map = "map3.txt" ;
    m_map = std::make_shared<map>("p3.png","map3.txt");
    m_map->map_number = 3 ;
    m_Root.AddChild(m_map);
    m_CurrentState = State::UPDATE;
    m_tool = std::make_shared<heroattack>(std::vector<std::string>{RESOURCE_DIR"/attack_tool/sword1.png",RESOURCE_DIR"/attack_tool/sword2.png",RESOURCE_DIR"/attack_tool/sword3.png",RESOURCE_DIR"/attack_tool/sword4.png",RESOURCE_DIR"/attack_tool/sword5.png"});
    m_Root.AddChild(m_tool) ;

    generate_enemy.generat(m_Root,all_enemy) ;

//    std::shared_ptr<caterpillar> Caterpillar = std::make_shared<caterpillar>() ;
//    auto temp = std::dynamic_pointer_cast<Util::GameObject>(Caterpillar) ;
//     slime = std::make_shared<Slime>() ;
//    slime->SetPosition({100,30});
//    temp->AddChild(std::dynamic_pointer_cast<Util::GameObject>(slime));
//
//    m_Root.AddChild(temp) ;
//   // temp = std::dynamic_pointer_cast<Util::GameObject>(all_enemy[1]) ;
//    m_Root.RemoveChild(temp);
}

void App::Update() {
    m_hero->run() ;
    phy.object_position.push_back(m_hero->GetPosition()) ;
    if(phy.jump_total.empty()){
        phy.jump_total.push_back(0);
    }
    for(int i = all_enemy.size()-1 ; i >=0 ; i--){
        if(all_enemy[i]->HP <= 0 && all_enemy[i]->hp_state != "die"){
            all_enemy[i]->bomb();
            continue;
        }else if(all_enemy[i]->hp_state == "die" && all_enemy[i]->Getplaystate() == Util::Animation::State::ENDED){
            m_Root.RemoveChild(all_enemy[i]) ;
            all_enemy.erase(all_enemy.begin() + i);
            continue;
        }
        if(all_enemy[i]->hp_state != "die"){
            all_enemy[i]->attack(m_hero);
            all_enemy[i]->move_even() ;
        }
    }
    phy.state.push_back(m_hero->hero_state) ;

    for(size_t i = 0 ; i < all_enemy.size() ; i ++){
            phy.object_position.push_back(all_enemy[i]->GetPosition()) ;
            phy.state.push_back(all_enemy[i]->state) ;
            phy.jump_total.push_back(0);
    }
    phy.in_sky_down();
    m_hero->hero_state = phy.get_state(0);
    m_hero->SetPosition(phy.object_position[0]);
    for(size_t i = 0 ; i < all_enemy.size() ; i ++) {
        if(!(all_enemy[i]->enemy_name == "prob" && all_enemy[i]->HP >= 2 && all_enemy[i]->HP < 500)){
            all_enemy[i]->state = phy.get_state(i + 1);
            all_enemy[i]->SetPosition(phy.object_position[i + 1]);
        }

    }
    phy.state.clear() ;
    m_map->hero_position = m_hero->GetPosition() ;
    m_map->Transitions(phy.jump_total,m_Root,all_enemy) ;
    m_hero->SetPosition(m_map->hero_position) ;
    phy.set_data("map" + std::to_string(m_map->map_number) + ".txt");
    m_hero->map = "map" + std::to_string(m_map->map_number) + ".txt" ;
    m_tool->SetPosition(m_hero->GetPosition()) ;
    m_tool->renw_position(m_hero->forward) ;
    m_tool->attack(m_hero->forward,all_enemy,m_Root,m_hero->nocontrol) ;
    if (Util::Input::IsKeyDown(Util::Keycode::ESCAPE)) {
        m_CurrentState = State::END ;
    }
    if (m_hero->HP <= 0 && m_hero->over_trans) {
        m_CurrentState = State::GameOver ;  // 退出更新循环，游戏结束
    }
    m_Root.Update() ;


    //m_map.SetImage("p1.png") ;
    //TODO: do your things here and delete this line <3

    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    /*
    Util::Image map(RESOURCE_DIR"/background/p1.png");
    map.Draw({{0,0},0,{2,2}},-10) ;
     */
}
void App::Trans(){
    m_CurrentState = State::UPDATE ;
    m_Root.Update() ;
};

void App::GameOver() {
    auto gameOverScreen = std::make_shared<Util::Image>(RESOURCE_DIR"/app/game_over_background.png");
    gameOverScreen->Draw({{0, 0}, 0, {1, 1}}, 0);
    if (Util::Input::IsKeyDown(Util::Keycode::ESCAPE)) {
        m_CurrentState = State::END ;
    }
}
void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}