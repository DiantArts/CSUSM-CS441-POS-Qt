///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>
#include <POS/UI/Window.hpp>
#include <POS/UI/Screen/Home.hpp>
#include <DB/Products.hpp>

///////////////////////////////////////////////////////////////////////////
auto main(
    int argc,
    char *argv[]
) -> int
{
    ::std::shared_ptr<::db::Products> dbProducts{ ::db::Products::get() };
    // dbProducts->insert({ 1, "testProduct01", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct02", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct03", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct04", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct05", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct06", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct07", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct08", 1234, 1 });
    // dbProducts->insert({ 2, "testProduct09", 1234, 1 });
    // dbProducts->retrieve({ "1", "3" });
    // return 0;
    // ::pos::ui::Window window{ argc, argv, 1920, 1080, "MainPosSystemWindow" };
    ::pos::ui::Window window{ argc, argv, 720, 520, "MainPosSystemWindow" };
    ::pos::ui::screen::Home homeScreen{ window, dbProducts };
    window.linkVirtualKeyPad(homeScreen.getVirtualKeyPad());
    return window.exec();
}
