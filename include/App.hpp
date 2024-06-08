#ifndef APP_HPP
#define APP_HPP
#include "map.hpp"
#include "hero.hpp"
#include "enemy.hpp"
#include "heroattack.hpp"
#include "Slime.hpp"
#include "generate_enemy.hpp"
#include "pch.hpp" // IWYU pragma: export
#include "Util/Root.hpp"
#include "Util/BGM.hpp"
#include "Prop.hpp"
class App {
public:
    enum class State {
        RESTART,
        GameOver,
        gamestart,
        START,
        TRANS,
        UPDATE,
        BOSS,
        END,
    };
    void setheart_grid(int hero_hp) ;



    State GetCurrentState() const { return m_CurrentState; }
    void  Boss();
    void GameOver();
    void gamestart();
    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)
    void Trans() ;
    float scale_x = 3;
    int hp = 10;
private:
    void ValidTask();

private:
    std::shared_ptr<Util::GameObject> heart ;
    std::shared_ptr<Util::GameObject> heart_gird;
    std::shared_ptr<Util::GameObject> black;
    generate_enemy generate_enemy ;
    std::vector<std::shared_ptr<enemy>> all_enemy;//多形
    State m_CurrentState = State::gamestart;
    Util::Root m_Root;
    std::shared_ptr<Util::BGM> m_bgm;
    physics phy ;
    std::shared_ptr<heroattack> m_tool ;
    std::shared_ptr<hero>  m_hero ;
    std::shared_ptr<map> m_map;
    std::shared_ptr<Slime> slime;
    std::vector<std::shared_ptr<Prop>> prop ;
};

#endif