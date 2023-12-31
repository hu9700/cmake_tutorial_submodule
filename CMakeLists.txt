cmake_minimum_required(VERSION 3.2)
project(submod)

# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as neede
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downlaoded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again")
endif()    

add_subdirectory(./glfw)
target_include_directories(${PROJECT_NAME} PUBLIC glfw/include)
target_link_directories(${PROJECT_NAME} PRIVATE glfw/src)
target_link_libraries(${PROJECT_NAME} glfw)