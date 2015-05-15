cmake_minimum_required(VERSION 3.2)
project(PlayBeat)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/bdd/BDDManager.hxx
    src/bdd/BDDManager.cxx
    src/dsgl/dotFile/tokens/Tokens.cxx
    src/dsgl/dotFile/tokens/Tokens.hxx
    src/dsgl/dotFile/DotFileLoader.cxx
    src/dsgl/dotFile/DotFileLoader.hxx
    src/dsgl/dotFile/Lexer.cxx
    src/dsgl/dotFile/Lexer.hxx
    src/dsgl/dotFile/Parser.cxx
    src/dsgl/dotFile/Parser.hxx
    src/dsgl/dotFile/ParsingException.hxx
    src/dsgl/Graph.cxx
    src/dsgl/Graph.hxx
    src/dsgl/GraphException.hxx
    src/dsgl/Node.cxx
    src/dsgl/Node.hxx
    src/tools/StringFormat.cxx
    src/tools/StringFormat.hxx
    src/main.cxx
    src/MusicMetadata.hxx
    src/notes.cxx
    src/notes.hxx
    src/notescounter.cxx
    src/notescounter.hxx
    src/notesfactory.cxx
    src/notesfactory.hxx
    src/playbeat.cxx
    src/playbeat.hxx)

add_executable(PlayBeat ${SOURCE_FILES})

LINK_DIRECTORIES(/usr/include/)
target_link_libraries(PlayBeat aubio tag sqlite3)
