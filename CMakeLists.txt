cmake_minimum_required(VERSION 3.3)
project(L3_AD_F5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Probleme.cpp Probleme.h Contrainte.cpp Contrainte.h Variable.cpp Variable.h Utilitaire.cpp Utilitaire.h)
add_executable(L3_AD_F5 ${SOURCE_FILES})