#include "Engine.h"
#include <boost/chrono.hpp>

// example-test function to generate Gosper glider gun shooting gliders
void set_gun(Engine& engine)
{
    engine.set_cell_state(5, 1);
    engine.set_cell_state(5, 2);
    engine.set_cell_state(6, 1);
    engine.set_cell_state(6, 2);
    engine.set_cell_state(5, 11);
    engine.set_cell_state(6, 11);
    engine.set_cell_state(7, 11);
    engine.set_cell_state(4, 12);
    engine.set_cell_state(3, 13);
    engine.set_cell_state(3, 14);
    engine.set_cell_state(8, 12);
    engine.set_cell_state(9, 13);
    engine.set_cell_state(9, 14);
    engine.set_cell_state(6, 15);
    engine.set_cell_state(4, 16);
    engine.set_cell_state(5, 17);
    engine.set_cell_state(6, 17);
    engine.set_cell_state(7, 17);
    engine.set_cell_state(6, 18);
    engine.set_cell_state(8, 16);
    engine.set_cell_state(3, 21);
    engine.set_cell_state(4, 21);
    engine.set_cell_state(5, 21);
    engine.set_cell_state(3, 22);
    engine.set_cell_state(4, 22);
    engine.set_cell_state(5, 22);
    engine.set_cell_state(2, 23);
    engine.set_cell_state(6, 23);
    engine.set_cell_state(1, 25);
    engine.set_cell_state(2, 25);
    engine.set_cell_state(6, 25);
    engine.set_cell_state(7, 25);
    engine.set_cell_state(3, 35);
    engine.set_cell_state(4, 35);
    engine.set_cell_state(3, 36);
    engine.set_cell_state(4, 36);
}

int main()
{
    // generate field 200x200
    Engine engine(200, 200);

    // set test cells
    set_gun(engine);

    // run 10000 generation to calculate time
#if 1
    boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
    engine.next_generation(10000);
    boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
         std::cout << "took " << sec.count() << " seconds\n";
    //engine.display(0);
#endif
    // run in display mode
#if 0
    while(true)
    {
        engine.display(1);
        engine.next_generation();
    }
#endif
}
