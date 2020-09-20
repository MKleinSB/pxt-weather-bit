/**
* Mary West @ SparkFun Electronics 
* Ryan Mortenson https://github.com/ryanjmortenson
* June 13, 2017
* https://github.com/sparkfun/pxt-weather-bit

* Development environment specifics:
* Written in Microsoft PXT
* Tested with a SparkFun weather:bit for micro:bit
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Please review the LICENSE.md file included with this example. If you have any questions 
* or concerns with licensing, please contact techsupport@sparkfun.com.
* Distributed as-is; no warranty is given.
*/


//% color=#f44242 icon="\u26C8"
namespace weatherbit {


    // Functions for interfacing with the soil moisture and soil temperature (aquaponics)


    /**
     * Reads the Moisture Level from the Soil Moisture Sensor.
	 * Returns a value between 0 and 1023. 0 being dry and 1023 being wet.     
     */
    //% weight=11 blockGap=8 blockId="weatherbit_soilMoisture" block="soil moisture"
    export function soilMoisture(): number {
        let soilMoisture = 0
        
        return soilMoisture
    }
    /**
     * Reads the temperature from the one-wire temperature sensor.
	 * Returns a 4 digit number. value should be divided by 100 to get 
	 *temperature in hudnreths of a degree centigrade. 
     */
    //% weight=10 blockId="weahterbit_soilTemp" block="soil temperature(C)"
    //% shim=weatherbit::soilTemp
    export function soilTemperature(): number {
        // Fake function for simulator
        return 0
    }
}
