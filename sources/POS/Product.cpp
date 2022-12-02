///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <POS/Product.hpp>


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Static
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::pos::Product::getFromDataBase(
    const ::std::string& id,
    ::std::shared_ptr<::db::Products> dbProducts
) -> Product
{
    if (id.empty()) {
        throw ::std::runtime_error{ "No ID specified" };
    }
    auto productVector{ dbProducts->retrieve({ id }) };
    if (productVector.empty()) {
        throw ::std::runtime_error{ "The ID '"s + id + "' does not match any product" };
    }
    return productVector[0];
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::pos::Product::Product(
    ::std::size_t id,
    ::std::string name,
    ::std::int64_t price,
    ::std::size_t quantity
) noexcept
    : m_id{ id }
    , m_name{ name }
    , m_price{ price }
    , m_quantity{ quantity }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Accessors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::pos::Product::getId() const
    -> ::std::size_t
{
    return m_id;
}

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::pos::Product::getName() const
    -> const ::std::string&
{
    return m_name;
}

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::pos::Product::getPrice() const
    -> ::std::int64_t
{
    return m_price;
}

///////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////
auto ::pos::Product::getQuantity() const
    -> ::std::size_t
{
    return m_quantity;
}
