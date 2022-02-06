set(SRCS
    main.cpp
    Command.cpp
    Shell.cpp
    nanotekspice.cpp
    components/N4071.cpp
    components/N4081.cpp
    components/N4011.cpp
    components/N4001.cpp
    components/N4030.cpp
    components/N4069.cpp
    )

add_executable (nanotekspice ${SRCS})

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/nanotekspice
  DESTINATION bin
  RENAME ${CMAKE_PROJECT_NAME}-nanotekspice)