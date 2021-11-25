cmake_minimum_required(VERSION 3.20)
project(NHF_l C)

set(CMAKE_C_STANDARD 99)

add_executable(NHF_l main.c fajlkez.c fajlkez.h fofuggvenyek.c fofuggvenyek.h segedfuggvenyek.c segedfuggvenyek.h struktura.c struktura.h debugmalloc.h beillesztes.c beillesztes.h listazas.c listazas.h torles.c torles.h kereses.c kereses.h)
