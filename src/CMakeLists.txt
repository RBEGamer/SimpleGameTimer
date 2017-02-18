# CMAKE LISTS TXT FOR INI PARSER
cmake_minimum_required(VERSION 2.7)
project(FRM_TIMER_LIB)
file(GLOB Sources "*.cpp")
ADD_LIBRARY( _ini_parser STATIC frm_timer.cpp)
TARGET_LINK_LIBRARIES( _timer )
