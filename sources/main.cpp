///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>
#include <POS/UI/Window.hpp>
#include <POS/UI/Screen/Home.hpp>

///////////////////////////////////////////////////////////////////////////
auto main(
    int argc,
    char *argv[]
) -> int
{
    // ::QPushButton* m_button;
    // , m_button{ new ::QPushButton{ &m_window } }


    // QApplication a(argc, argv);
    // QWidget *widget = new QWidget();
    // auto l = new QHBoxLayout(widget);
    // widget->setLayout(l);
    // auto *e = new QTextEdit(widget);
    // auto *t = new QTextEdit(widget);
    // l->addWidget(e);
    // l->addWidget(t);

    // QObject::connect(e, &QTextEdit::textChanged, [=]() {
        // t->setHtml(e->toPlainText());
    // });

    // widget->show();

    ::pos::ui::Window window{ argc, argv, 720, 520, "MainPosSystemWindow" };
    ::pos::ui::screen::Home homeScreen{ window };
    return window.exec();
}
