///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <POS/UI/Screen/Home.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::pos::ui::screen::Home::Home(
    ::pos::ui::Window& window
) noexcept
    : m_window{ window }
    , m_products{
        m_window.get(),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.4),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.9)
    } , m_virtualKeyPad {
        m_window.get(),
        m_products,
        static_cast<::std::size_t>(m_window.getSize().width() * 0.55),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.4),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.9)
    } , m_deletProductButton{
        m_window.get(),
        "deleteIcon.png",
        static_cast<::std::size_t>(m_window.getSize().width() * 0.46),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.08),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.08),
        [this](){ m_products.removeSelected(); }
    }
{
    m_products.emplace(1uz, "article1"s, 10.20f, 2uz);
    m_products.emplace(1uz, "article2"s, 22.31f, 1uz);
}
