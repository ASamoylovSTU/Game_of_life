#define BOOST_TEST_MODULE Game_of_life_engine

#include <boost/test/unit_test.hpp>

#include "Engine.h"

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
        uchar* test = new uchar[100 * 100];
        for(ushort i = 0; i < 100 * 100; i++)
        {
            test[i] = 0;
        }
        test[103] = 1; // central
        test[2] = 0x2; // upper left
        test[3] = 0x2; // upper
        test[4] = 0x2; // upper right
        test[102] = 0x2; // left
        test[104] = 0x2; // right
        test[202] = 0x2; // bottom left
        test[203] = 0x2; // bottom
        test[204] = 0x2; // bottom right
        auto equal_arr = [](uchar* pt1, uchar* pt2, ushort size)
        {
            for(ushort i = 0; i < size; i++)
            {
                if (pt1[i] != pt2[i])
                {
                    return false;
                }
            }
            return true;
        };
        BOOST_CHECK(equal_arr(engine.get_matrix(), test, 100*100));
    }

    BOOST_AUTO_TEST_CASE(set_dead_cell)
    {
        Engine engine(100, 100);
        engine.set_cell_state(3, 1);
        engine.set_cell_state(3, 1, false);
        uchar* test = new uchar[100 * 100];
        for(ushort i = 0; i < 100 * 100; i++)
        {
            test[i] = 0;
        }
        auto equal_arr = [](uchar* pt1, uchar* pt2, ushort size)
        {
            for(ushort i = 0; i < size; i++)
            {
                if (pt1[i] != pt2[i])
                {
                    return false;
                }
            }
            return true;
        };
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
        uchar* test = new uchar[10 * 10];
        for(ushort i = 0; i < 10 * 10; i++)
        {
            test[i] = 0;
        }
        // first row
        test[1] = 0x2;
        test[2] = 0x2;
        test[3] = 0x2;
        // second row
        test[11] = 0x4;
        test[12] = 0x3;
        test[13] = 0x4;
        // third row
        test[21] = 0x6;
        test[22] = 0x5;
        test[23] = 0x6;
        // fourth row
        test[31] = 0x4;
        test[32] = 0x3;
        test[33] = 0x4;
        // fifth row
        test[41] = 0x2;
        test[42] = 0x2;
        test[43] = 0x2;
        auto equal_arr = [](uchar* pt1, uchar* pt2, ushort size)
        {
            for(ushort i = 0; i < size; i++)
            {
                if (pt1[i] != pt2[i])
                {
                    return false;
                }
            }
            return true;
        };
        BOOST_CHECK(equal_arr(engine.get_matrix(), test, 10*10));
    }

    BOOST_AUTO_TEST_CASE(next_generation_5)
    {
        Engine engine(10, 10);
        engine.set_cell_state(2, 2);
        engine.set_cell_state(1, 2);
        engine.set_cell_state(3, 2);

        engine.next_generation(5);
        uchar* test = new uchar[10 * 10];
        for(ushort i = 0; i < 10 * 10; i++)
        {
            test[i] = 0;
        }
        // first row
        test[1] = 0x2;
        test[2] = 0x2;
        test[3] = 0x2;
        // second row
        test[11] = 0x4;
        test[12] = 0x3;
        test[13] = 0x4;
        // third row
        test[21] = 0x6;
        test[22] = 0x5;
        test[23] = 0x6;
        // fourth row
        test[31] = 0x4;
        test[32] = 0x3;
        test[33] = 0x4;
        // fifth row
        test[41] = 0x2;
        test[42] = 0x2;
        test[43] = 0x2;
        auto equal_arr = [](uchar* pt1, uchar* pt2, ushort size)
        {
            for(ushort i = 0; i < size; i++)
            {
                if (pt1[i] != pt2[i])
                {
                    return false;
                }
            }
            return true;
        };
        BOOST_CHECK(equal_arr(engine.get_matrix(), test, 10*10));
    }

BOOST_AUTO_TEST_SUITE_END()
