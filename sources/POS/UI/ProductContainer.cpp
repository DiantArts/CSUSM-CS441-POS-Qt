///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <POS/UI/ProductContainer.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::pos::ui::ProductContainer::ProductContainer(
    ::QMainWindow& window
) noexcept
    : ::pos::ui::ProductContainer{ window, 0, 0, 0, 0 }
{}

///////////////////////////////////////////////////////////////////////////
::pos::ui::ProductContainer::ProductContainer(
    ::QMainWindow& window,
    ::std::size_t xPos,
    ::std::size_t yPos,
    ::std::size_t xSize,
    ::std::size_t ySize
) noexcept
    : m_window{ window }
    , m_table{ new QTableWidget{ 0, 3, &window } }
    , m_totalTextBox{ window, xPos, yPos + ySize - 18, xSize, 18 }
{
    m_table->move(static_cast<int>(xPos), static_cast<int>(yPos));
    m_table->resize(static_cast<int>(xSize), static_cast<int>(ySize - 20));
    m_table->verticalHeader()->hide();
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);

    {
        QStringList headers;
        headers << "Price" << "Quantity" << "Name";
        m_table->setHorizontalHeaderLabels(headers);
    }

    m_table->setColumnWidth(0, 80);
    m_table->setColumnWidth(1, 60);
    m_table->horizontalHeader()->setStretchLastSection(true);

    m_totalTextBox.setVerticalScrollBarPolicy(::Qt::ScrollBarAlwaysOff);
    this->printTotal();
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Accessors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::pos::ui::ProductContainer::add(
    const ::pos::Product& product
) -> ::std::size_t
{
    m_products.push_back(product);

    const auto index{ m_products.size() - 1 };

    m_table->insertRow(static_cast<int>(index));
    m_table->setCurrentIndex(m_table->model()->index(static_cast<int>(index), 0));

    m_table->setItem(static_cast<int>(index), 0, new ::QTableWidgetItem{ ::fmt::format("${:.2f}",
        product.getPrice() * static_cast<float>(product.getQuantity())
    ).c_str() });
    m_table->setItem(static_cast<int>(index), 1, new ::QTableWidgetItem{ ::fmt::format("{}",
        product.getQuantity()
    ).c_str() });
    m_table->setItem(static_cast<int>(index), 2, new ::QTableWidgetItem{ ::fmt::format("{}",
        product.getName()
    ).c_str() });

    this->printTotal();

    return index;
}

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::ProductContainer::remove(
    ::std::size_t productIndex
)
{
    m_table->removeRow(static_cast<int>(productIndex));
    m_products.erase(m_products.begin() + static_cast<long>(productIndex));
    this->printTotal();
}

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::ProductContainer::removeSelected()
{
    if (!m_products.empty()) {
        auto productIndex{ m_table->selectionModel()->selectedRows().front().row() };
        m_table->removeRow(productIndex);
        m_products.erase(m_products.begin() + productIndex);
        if (productIndex) {
            m_table->setCurrentIndex(m_table->model()->index(productIndex - 1, 0));
        } else {
            m_table->setCurrentIndex(m_table->model()->index(0, 0));
        }
        this->printTotal();
    } else {
        QMessageBox* msg = new QMessageBox{ &m_window };
        msg->setText("No remaining item to delete");
        msg->setWindowFlags(msg->windowFlags() | Qt::WindowStaysOnTopHint);
        msg->setStyleSheet(
            "background-color: #FFFFFF; "
            "color:rgb(255,0,0); "
            "font-size: 15px; "
            "QMessageBox { border-color: rgb(0, 0, 0); "
            "border-style: none; "
            "border-width: 0px; }"
        );
        msg->setModal(false);
        msg->setStandardButtons(QMessageBox::StandardButton::NoButton);
        msg->show();
        QTimer::singleShot(1500, msg, SLOT(hide()));
        m_window.setFocus();
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::pos::ui::ProductContainer::printTotal()
{
    auto total{ 0.0f };
    for (const auto& p : m_products) {
        total += p.getPrice() * static_cast<float>(p.getQuantity());
    }
    m_totalTextBox.clearLine();
    m_totalTextBox.addLine(::fmt::format("Total: ${:.2f}", total));
    m_totalTextBox.print();
}
