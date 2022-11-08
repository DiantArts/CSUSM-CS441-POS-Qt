///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <POS/UI/Box/ATextBox.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::pos::ui::box::ATextBox::ATextBox(
    ::QMainWindow& window
) noexcept
    : ::pos::ui::box::ATextBox{ window, 0, 0, 0, 0 }
{}

///////////////////////////////////////////////////////////////////////////
::pos::ui::box::ATextBox::ATextBox(
    ::QMainWindow& window,
    ::std::size_t xPos,
    ::std::size_t yPos,
    ::std::size_t xSize,
    ::std::size_t ySize
) noexcept
    : ::QTextEdit{ &window }
    , m_xPos{ xPos }
    , m_yPos{ yPos }
    , m_xSize{ xSize }
    , m_ySize{ ySize }
{
    this->updateGeometry();
    this->setAlignment(::Qt::AlignLeft);
    this->setReadOnly(true);
    this->show();
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Rule of 5
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// \brief Destructor
///
///////////////////////////////////////////////////////////////////////////
::pos::ui::box::ATextBox::~ATextBox() noexcept = default;



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Accessors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::box::ATextBox::addText(
    const ::std::string& text
)
{
    m_lines.back() += text;
}

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::box::ATextBox::addLine(
    const ::std::string& line
)
{
    m_lines.push_back(line);
}

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::box::ATextBox::clearLine()
{
    m_lines.clear();
}

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::box::ATextBox::print()
{
    ::std::string str;
    for (const auto& line : m_lines) {
        str += line;
        str += '\n';
    }
    if (!str.empty()) {
        str.erase(str.size() - 1);
    }
    this->setText(::QString{ str.c_str() });
}

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::box::ATextBox::setPosition(
    ::std::size_t xPos,
    ::std::size_t yPos
)
{
    m_xPos = xPos;
    m_yPos = yPos;
    this->updateGeometry();
}

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::box::ATextBox::resize(
    ::std::size_t xSize,
    ::std::size_t ySize
)
{
    m_xSize = xSize;
    m_ySize = ySize;
    this->updateGeometry();
}

///////////////////////////////////////////////////////////////////////////
auto ::pos::ui::box::ATextBox::getText() const
    -> ::std::string
{
    ::std::string str;
    for (const auto& line : m_lines) {
        str += line;
        str += '\n';
    }
    if (!str.empty()) {
        str.erase(str.size() - 1);
    }
    return str;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::box::ATextBox::updateGeometry()
{
    this->setGeometry(
        static_cast<int>(m_xPos),
        static_cast<int>(m_yPos),
        static_cast<int>(m_xSize),
        static_cast<int>(m_ySize)
    );
}
