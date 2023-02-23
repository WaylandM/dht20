// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/RobTillaart/DHT20"

//Include C++ libraries
#include <DHT20.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = DHT20*;
    }
    
    uint8_t mem[sizeof(DHT20)];

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto wire = getValue<input_I2C>(ctx);
        
        // Create an object of the class DHT20.
        Type sensor = new (mem) DHT20(wire);
        emitValue<output_DEV>(ctx, sensor);
    }
}
