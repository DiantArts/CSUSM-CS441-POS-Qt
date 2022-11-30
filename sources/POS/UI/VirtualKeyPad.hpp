#pragma once

#include <POS/UI/Box/ATextBox.hpp>
#include <POS/UI/Button/CustomText.hpp>
#include <POS/UI/ProductContainer.hpp>

namespace pos::ui {

///////////////////////////////////////////////////////////////////////////
/// \brief Enable number typing with virtual key pad
/// \ingroup ecs
///
/// \include VirtualKeyPad.hpp <POS/UI/Button/VirtualKeyPad.hpp>
///
/// 9 buttons and a text box
///
///////////////////////////////////////////////////////////////////////////
class VirtualKeyPad
{

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit VirtualKeyPad(
        ::QMainWindow& window,
        ::std::size_t visibleXPos,
        ::std::size_t visibleYPos,
        ::std::size_t unvisibleXPos,
        ::std::size_t unvisibleYPos,
        ::std::size_t xSize,
        ::std::size_t ySize
    ) noexcept;




    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Animatiton
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void reveal(
        ::std::function<void(const ::std::string&)> validateCallback
    );

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void conceal();

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void write(
        const ::std::string& str
    );



private:

    bool m_isVisible{ false };
    ::std::size_t m_visibleXPos;
    ::std::size_t m_visibleYPos;
    ::std::size_t m_unvisibleXPos;
    ::std::size_t m_unvisibleYPos;

    ::QSize m_buttonSize;

    ::std::optional<::std::function<void(const ::std::string&)>> m_validateCallback;

    ::pos::ui::box::ATextBox m_textBox;
    ::std::array<::pos::ui::button::CustomText, 16> m_buttons;

    ::QPropertyAnimation m_textBoxAnimation;
    ::std::array<::QPropertyAnimation, 16> m_buttonAnimations;

    static inline constexpr const ::std::size_t animationDuration{ 200 };

};

} // namespace pos::ui::button
