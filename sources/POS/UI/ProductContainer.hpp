#pragma once

#include <POS/UI/Box/ATextBox.hpp>
#include <POS/Product.hpp>
#include <DB/Cart.hpp>

namespace pos::ui {

///////////////////////////////////////////////////////////////////////////
/// \brief Container of products that is linked to a text box
/// \ingroup ecs
///
/// \include ProductContainer.hpp <POS/UI/ProductContainer.hpp>
///
/// Contains a ::QApplication and a ::QMainWindow window
///
///////////////////////////////////////////////////////////////////////////
class ProductContainer
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
    /// forward to the other constructor while passing null valuesa
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit ProductContainer(
        ::QMainWindow& window,
        ::std::shared_ptr<::db::Products> dbProducts
    ) noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    /// Sets all variables except the string
    ///
    /// \see ::pos::ui::ATextBox
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit ProductContainer(
        ::QMainWindow& window,
        ::std::shared_ptr<::db::Products> dbProducts,
        ::std::size_t xPos,
        ::std::size_t yPos,
        ::std::size_t xSize,
        ::std::size_t ySize
    ) noexcept;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Operations
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void load(
        const ::std::string& id
    );

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void save();



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Accessors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief add a product to the list
    ///
    /// returns the index in the list
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto emplace(
        auto&&... args
    ) -> ::std::size_t;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief get the number of products in the cart
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto size()
        -> ::std::size_t;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief add a product to the list
    ///
    /// returns the index in the list
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto add(
        const ::pos::Product& product
    ) -> ::std::size_t;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief search in the DB
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto emplaceFromId(
        const ::std::vector<::std::string>& id
    ) -> ::std::size_t;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto addFunds(
        const ::std::vector<::std::string>& id
    ) -> ::std::size_t;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto pay()
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief remove the product at the index given as parameter
    ///
    ///////////////////////////////////////////////////////////////////////////
    void remove(
        ::std::size_t productIndex
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief remove the product at the index given as parameter
    ///
    ///////////////////////////////////////////////////////////////////////////
    void removeSelected();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief clear all the items
    ///
    ///////////////////////////////////////////////////////////////////////////
    void clear();

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setReadOnly(
        bool value
    );



private:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Helpers
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void printTotal();

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void printFunds();



private:

    ::QMainWindow& m_window;
    ::std::shared_ptr<::db::Products> m_dbProducts;

    ::std::deque<::pos::Product> m_products;

    ::QTableWidget* m_table;
    ::pos::ui::ATextBox m_totalTextBox;

    ::std::int64_t m_funds{ 0 };
    ::pos::ui::ATextBox m_fundsTextBox;

    ::std::string m_id;

};

} // namespace pos::ui

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Header-implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
#include <POS/UI/ProductContainer.impl.hpp>
