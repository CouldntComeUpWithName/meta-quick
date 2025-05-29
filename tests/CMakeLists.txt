if(BUILD_TESTING)

  add_executable(test1)

  target_sources(test1 PRIVATE "static-type-name-test.cpp")

  target_link_libraries(test1 PUBLIC meta-quick)

endif()