
###
#Main
    add_executable(${PROJECT_NAME} main.cpp include/controller.h)
    target_link_libraries(  ${PROJECT_NAME} 
                            ${Boost_LIBRARIES}
                        )

    install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

