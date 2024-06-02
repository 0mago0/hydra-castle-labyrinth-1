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
        END,
    };
    std::vector<std::shared_ptr<Util::GameObject>> list;
    std::vector<std::shared_ptr<Util::GameObject>> list1;
    std::shared_ptr<Util::GameObject> black;
    float scale_x = 3;
    std::vector<bool> status = {true, true, true, true, true, true, true, true, true, true };
    State GetCurrentState() const { return m_CurrentState; }

    void GameOver();
    void gamestart();
    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)
    void Trans() ;
    int hp = 10;
private:
    void ValidTask();

private:
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