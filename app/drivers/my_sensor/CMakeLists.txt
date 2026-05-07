if(CONFIG_MY_SENSOR)
    target_sources(app PRIVATE my_sensor.c)
    target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endif()