#pragma once

namespace pos::ui {

///////////////////////////////////////////////////////////////////////////
/// \brief Notifies an error
/// \ingroup ecs
///
/// \include ErrorNotification.hpp <POS/UI/Button/ErrorNotification.hpp>
///
///////////////////////////////////////////////////////////////////////////
class ErrorNotification
    : public ::QMessageBox
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
    explicit ErrorNotification(
        ::QMainWindow& window,
        const ::std::string& text
    ) noexcept;

};

} // namespace pos::ui
