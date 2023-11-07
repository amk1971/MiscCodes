idf_component_register(SRCS "bme280_spi.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES "bme280_common" "CPPSPI")

#set(COMPONENT_PRIV_REQUIRES bme280_common CPPSPI)