#define BOOST_TEST_MODULE Game_of_life_engine

#include <boost/test/unit_test.hpp>

#include "Engine.h"


bool equal_arr(shared_uchar_array pt1, shared_uchar_array pt2, ushort size)
{
    for(ushort i = 0; i < size; i++)
    {
        if (pt1.get()[i] != pt2.get()[i])
        {
            std::cerr << i << " " << (int)pt1.get()[i] << " " << (int)pt2.get()[i] << std::endl;
            return false;
        }
    }
    return true;
};

BOOST_AUTO_TEST_SUITE(set_cell_state)

    BOOST_AUTO_TEST_CASE(X_is_bigger_than_width)
    {
        Engine engine(100, 100);
        BOOST_CHECK_THROW (engine.set_cell_state(200, 10), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(Y_is_bigget_than_height)
    {
        Engine engine(100, 100);
        BOOST_CHECK_THROW (engine.set_cell_state(10, 200), std::runtime_error);
    }
    BOOST_AUTO_TEST_CASE(set_live_cell)
    {
        Engine engine(100, 100);
        engine.set_cell_state(3, 1);
        shared_uchar_array test(new uchar[100 * 100], std::default_delete<uchar[]>());
        for(size_t i = 0; i < 100 * 100; i++)
        {
            test.get()[i] = 0;
        }
        test.get()[103] = 1; // central
        test.get()[2] = 0x2; // upper left
        test.get()[3] = 0x2; // upper
        test.get()[4] = 0x2; // upper right
        test.get()[102] = 0x2; // left
        test.get()[104] = 0x2; // right
        test.get()[202] = 0x2; // bottom left
        test.get()[203] = 0x2; // bottom
        test.get()[204] = 0x2; // bottom right
        BOOST_CHECK(equal_arr(engine.get_matrix(), test, 100*100));
    }

    BOOST_AUTO_TEST_CASE(set_dead_cell)
    {
        Engine engine(100, 100);
        engine.set_cell_state(3, 1);
        engine.set_cell_state(3, 1, false);
        shared_uchar_array test(new uchar[100 * 100], std::default_delete<uchar[]>());
        for(size_t i = 0; i < 100 * 100; i++)
        {
            test.get()[i] = 0;
        }
        BOOST_CHECK(equal_arr(engine.get_matrix(), test, 100*100));
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(next_generation)

    BOOST_AUTO_TEST_CASE(next_generation_is_0)
    {
        Engine engine(10, 10);
        BOOST_CHECK_THROW (engine.next_generation(0), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(next_generation_1)
    {
        Engine engine(10, 10);
        engine.set_cell_state(2, 2);
        engine.set_cell_state(1, 2);
        engine.set_cell_state(3, 2);

        engine.next_generation();
        shared_uchar_array test(new uchar[10 * 10], std::default_delete<uchar[]>());
        for(size_t i = 0; i < 10 * 10; i++)
        {
            test.get()[i] = 0;
        }
        // first row
        test.get()[1] = 0x2;
        test.get()[2] = 0x2;
        test.get()[3] = 0x2;
        // second row
        test.get()[11] = 0x4;
        test.get()[12] = 0x3;
        test.get()[13] = 0x4;
        // third row
        test.get()[21] = 0x6;
        test.get()[22] = 0x5;
        test.get()[23] = 0x6;
        // fourth row
        test.get()[31] = 0x4;
        test.get()[32] = 0x3;
        test.get()[33] = 0x4;
        // fifth row
        test.get()[41] = 0x2;
        test.get()[42] = 0x2;
        test.get()[43] = 0x2;
        BOOST_CHECK(equal_arr(engine.get_matrix(), test, 10*10));
    }

    BOOST_AUTO_TEST_CASE(next_generation_5)
    {
        Engine engine(10, 10);
        engine.set_cell_state(2, 2);
        engine.set_cell_state(1, 2);
        engine.set_cell_state(3, 2);

        engine.next_generation(5);
        shared_uchar_array test(new uchar[10 * 10], std::default_delete<uchar[]>());
        for(size_t i = 0; i < 10 * 10; i++)
        {
            test.get()[i] = 0;
        }
        // first row
        test.get()[1] = 0x2;
        test.get()[2] = 0x2;
        test.get()[3] = 0x2;
        // second row
        test.get()[11] = 0x4;
        test.get()[12] = 0x3;
        test.get()[13] = 0x4;
        // third row
        test.get()[21] = 0x6;
        test.get()[22] = 0x5;
        test.get()[23] = 0x6;
        // fourth row
        test.get()[31] = 0x4;
        test.get()[32] = 0x3;
        test.get()[33] = 0x4;
        // fifth row
        test.get()[41] = 0x2;
        test.get()[42] = 0x2;
        test.get()[43] = 0x2;
        BOOST_CHECK(equal_arr(engine.get_matrix(), test, 10*10));
    }

BOOST_AUTO_TEST_SUITE_END()
