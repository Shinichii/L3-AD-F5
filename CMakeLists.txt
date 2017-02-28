cmake_minimum_required(VERSION 3.3)
project(L3_AD_F5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES L3-AD-F5-main.cpp L3-AD-F5-Probleme.cpp L3-AD-F5-Probleme.h L3-AD-F5-Contrainte.cpp L3-AD-F5-Contrainte.h L3-AD-F5-Variable.cpp L3-AD-F5-Variable.h L3-AD-F5-Utilitaire.cpp L3-AD-F5-Utilitaire.h)
add_executable(L3_AD_F5 ${SOURCE_FILES})