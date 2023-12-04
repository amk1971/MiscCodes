#include <iostream>

#include "cppspi.h"

#include "bme280_spi.h"

extern "C" {
    void app_main(void);
}


constexpr static int SPI_3_MISO = 19;
constexpr static int SPI_3_MOSI = 23;
constexpr static int SPI_3_SCLK = 18;
constexpr static int BME280_SS_PIN = 5;


CPPSPI::Spi spi3;

void app_main(void )
{    
    CPPBME280::BME280SPI bme280spi;
   

   

    // Initialize the SPI
    spi3.Init(SPI3_HOST, SPI_3_MISO, SPI_3_MOSI, SPI_3_SCLK);

    // Register BME280 device as SPI device using GPIO5 as the select pin
    bme280spi.InitSpi(&spi3, BME280_SS_PIN);
    // Initialize the BME280SPI device
    bme280spi.Init();
    bme280spi.SetMode(1);
    bme280spi.SetConfigFilter(1);

   

    float spiTemperature{};
    float spiPressure{};
    int spiHumidity{};
    int spiId{};

    

    while(true)
    {
        spiId = bme280spi.GetDeviceID();
        
        bme280spi.GetAllResults(&spiTemperature, &spiHumidity, &spiPressure);
       
        std::cout << "==================================================\n";
        std::cout << "SPI Temperature: " << spiTemperature << "c\n";
        std::cout << "SPI Humidity   : " << spiHumidity << "%\n";
        std::cout << "SPI Pressure   : " << spiPressure << "Pa\n";
        std::cout << "SPI ID         : " << spiId << '\n';

        std::cout << "--------------------------------------------------\n";

       

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}