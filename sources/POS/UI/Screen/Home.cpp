///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <POS/UI/Screen/Home.hpp>
#include <POS/UI/ErrorNotification.hpp>



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
        static_cast<::std::size_t>(m_window.getSize().width() * 0.50),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.9)
    }, m_virtualKeyPad {
        m_window.get(),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.56),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().width()),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.39),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.9)
    }, m_deleteProductButton{
        m_window.get(),
        "deleteIcon.png",
        static_cast<::std::size_t>(m_window.getSize().width() * 0.56),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.08),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.08),
        [this](){ m_products.removeSelected(); }
    }, m_clearProductButton{
        m_window.get(),
        "resetIcon.png",
        static_cast<::std::size_t>(m_window.getSize().width() * 0.56),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.15),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.08),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.08),
        [this](){ m_products.clear(); }
    }, m_payProductButton{
        m_window.get(),
        "payIcon.png",
        static_cast<::std::size_t>(m_window.getSize().width() * 0.56),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.25),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.08),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.08),
        [this](){
            new ::pos::ui::ErrorNotification{ m_window.get(), "Insufficient funds" };
        }
    }, m_addProductButton{
        m_window.get(),
        "addIcon.png",
        static_cast<::std::size_t>(m_window.getSize().width() * 0.65),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.05),
        static_cast<::std::size_t>(m_window.getSize().width() * 0.08),
        static_cast<::std::size_t>(m_window.getSize().height() * 0.08),
        [this](){
            m_virtualKeyPad.reveal(
                ::std::bind_front(&::pos::ui::ProductContainer::emplaceFromId, &m_products)
            );
            // new ::pos::ui::ErrorNotification{ m_window.get(), "Insufficient funds" };
        }
    }
{
    m_products.emplace(1uz, "article1"s, 10.20f, 2uz);
    m_products.emplace(1uz, "article2"s, 22.31f, 1uz);
}
