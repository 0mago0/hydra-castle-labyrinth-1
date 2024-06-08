#include "App.hpp"

#include "Core/Context.hpp"

//int main(int, char**) {
//    auto context = Core::Context::GetInstance();
//    App app;
//
//    while (!context->GetExit()) {
//        switch (app.GetCurrentState()) {
//            case App::State::START:
//                app.Start();
//                break;
//            case App::State::UPDATE:
//                app.Update();
//                break;
//            case App::State::TRANS:
//                app.Trans();
//                break;
//            case App::State::gamestart:
//                app.gamestart();
//                break;
//            case App::State::GameOver:
//                app.GameOver();
//                break;
//            case App::State::END:
//                app.End();
//                context->SetExit(true);
//                break;
//        }
//        context->Update();
//    }
//    return 0;
//}
#include "App.hpp"

#include "Core/Context.hpp"

int main(int, char**) {
    auto context = Core::Context::GetInstance();
    std::shared_ptr<App> app = std::make_shared<App>();

    while (!context->GetExit()) {
        switch (app->GetCurrentState()) {
            case App::State::START:
                app->Start();
                break;
            case App::State::UPDATE:
                app->Update();
                break;
            case App::State::TRANS:
                app->Trans();
                break;
            case App::State::gamestart:
                app->gamestart();
                break;
            case App::State::GameOver:
                app->GameOver();
                break;
            case App::State::RESTART:
                app = std::make_shared<App>();
                app->Start();
                break;
            case App::State::BOSS:
                app->Boss();
                break ;
            case App::State::END:
                app->End();
                context->SetExit(true);
                break;


        }
        context->Update();
    }
    return 0;
}