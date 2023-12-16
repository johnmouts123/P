cmake_minimum_required(VERSION 3.22)
project(Trabalho_Prático C)

set(CMAKE_C_STANDARD 99)

add_executable(trabalho_pratico
        main.c
        paragens.c
        linhas.c
        utils.c
        menu.c
        menu.h
        paragens.h
        linhas.h
        utils.h
        )

