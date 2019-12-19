TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        card.cpp \
        deck.cpp \
        game.cpp \
        genericplayer.cpp \
        hand.cpp \
        house.cpp \
        main.cpp \
        player.cpp

HEADERS += \
    card.h \
    deck.h \
    game.h \
    genericplayer.h \
    hand.h \
    house.h \
    player.h
