#include "stdafx.h"

#define BOOST_TEST_MODULE test_foo
#include <boost/test/unit_test.hpp>
#include "shape.h"
#include <typeinfo>

#define LOG_LEVEL all

BOOST_AUTO_TEST_SUITE( test_shape_factory )

    BOOST_AUTO_TEST_CASE( test_shape_factory__check_circle_creating ) {
        BOOST_REQUIRE( nullptr != dynamic_cast<Circle*>( ShapeFactory::instantiate(Shapes::CIRCLE, 1, 2, 3).get() ));
    }

    BOOST_AUTO_TEST_CASE( test_shape_factory__check_ellipse_creating ) {
        BOOST_REQUIRE( nullptr != dynamic_cast<Ellipse*>( ShapeFactory::instantiate(Shapes::ELLIPSE, 1, 2, 3, 4, 5).get() ));
    }

    BOOST_AUTO_TEST_CASE( test_shape_factory__check_square_creating ) {
        BOOST_REQUIRE( nullptr != dynamic_cast<Square*>( ShapeFactory::instantiate(Shapes::SQUARE, 1, 2, 3, 4).get() ));
    }

BOOST_AUTO_TEST_SUITE_END()