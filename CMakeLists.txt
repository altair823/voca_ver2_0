cmake_minimum_required(VERSION 3.17)
project(voca_ver2_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(voca_ver2_0 main.cpp handler.cpp Voca_Header/handler.hpp File_ioHandler.cpp Voca_Header/File_ioHandler.hpp Data_Structure.cpp Voca_Header/Data_Structure.hpp Console_ioHandler.cpp Voca_Header/Console_ioHandler.hpp)
#find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})
#add_executable(BoostTest main.cpp handler.cpp Voca_Header/handler.hpp File_ioHandler.cpp Voca_Header/File_ioHandler.hpp Data_Structure.cpp Voca_Header/Data_Structure.hpp Console_ioHandler.cpp Voca_Header/Console_ioHandler.hpp)
#target_link_libraries(BoostTest ${Boost_LIBRARIES})