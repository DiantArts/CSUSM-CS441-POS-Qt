///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <POS/UI/VirtualKeyPad.hpp>
#include <POS/UI/ErrorNotification.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::pos::ui::VirtualKeyPad::VirtualKeyPad(
    ::QMainWindow& window,
    ::pos::ui::ProductContainer& products,
    ::std::size_t xPos,
    ::std::size_t yPos,
    ::std::size_t xSize,
    ::std::size_t ySize
) noexcept
    : m_buttonSize{ static_cast<int>(xSize / 3), static_cast<int>(ySize) / 5 }
    , m_products{ products }
    , m_textBox{
        window,
        xPos + m_buttonSize.width() * 0,
        yPos + m_buttonSize.height() * 0,
        xSize,
        static_cast<::std::size_t>(m_buttonSize.height()),
    } , m_keyPadButtons{
        ::pos::ui::button::CustomText{
            window,
            "clear",
            xPos + m_buttonSize.width() * 0,
            yPos + m_buttonSize.height() * 4,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.clearLine(); m_textBox.addLine(""); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "0",
            xPos + m_buttonSize.width() * 1,
            yPos + m_buttonSize.height() * 4,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("0"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "validate",
            xPos + m_buttonSize.width() * 2,
            yPos + m_buttonSize.height() * 4,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){
                try {
                    m_products.add(m_textBox.getText());
                    m_textBox.clearLine();
                    m_textBox.addLine("");
                    m_textBox.print();
                } catch (...) {}
            }
        }, ::pos::ui::button::CustomText{
            window,
            "1",
            xPos + m_buttonSize.width() * 0,
            yPos + m_buttonSize.height() * 3,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("1"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "2",
            xPos + m_buttonSize.width() * 1,
            yPos + m_buttonSize.height() * 3,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("2"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "3",
            xPos + m_buttonSize.width() * 2,
            yPos + m_buttonSize.height() * 3,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("3"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "4",
            xPos + m_buttonSize.width() * 0,
            yPos + m_buttonSize.height() * 2,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("4"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "5",
            xPos + m_buttonSize.width() * 1,
            yPos + m_buttonSize.height() * 2,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("5"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "6",
            xPos + m_buttonSize.width() * 2,
            yPos + m_buttonSize.height() * 2,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("6"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "7",
            xPos + m_buttonSize.width() * 0,
            yPos + m_buttonSize.height() * 1,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("7"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "8",
            xPos + m_buttonSize.width() * 1,
            yPos + m_buttonSize.height() * 1,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("8"); m_textBox.print(); }
        }, ::pos::ui::button::CustomText{
            window,
            "9",
            xPos + m_buttonSize.width() * 2,
            yPos + m_buttonSize.height() * 1,
            static_cast<::std::size_t>(m_buttonSize.width()),
            static_cast<::std::size_t>(m_buttonSize.height()),
            [this](){ m_textBox.addText("9"); m_textBox.print(); }
        }
    }
{
    m_textBox.setFontPointSize(25);
    m_textBox.addLine("");
}
