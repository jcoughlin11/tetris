#include <iostream>

#include <SDL3/SDL.h>

#include "tetris.hpp"

// ===========================================
//                  update
// ===========================================
void Tetris::update(const bool *keyStates) {
  _piece_move(keyStates);
  _gravity_apply();
  _piece_lock();
  _rows_clear();
  _piece_spawn();
}

// ===========================================
//               _piece_move
// ===========================================
void Tetris::_piece_move(const bool *keyStates) {
  if (keyStates[SDL_SCANCODE_A]) {
    std::cout << "Hello" << std::endl;
  }
}

// ===========================================
//              _gravity_apply
// ===========================================
void Tetris::_gravity_apply(void) {}

// ===========================================
//               _piece_lock
// ===========================================
void Tetris::_piece_lock(void) {}

// ===========================================
//               _rows_clear
// ===========================================
void Tetris::_rows_clear(void) {}

// ===========================================
//               _piece_spawn
// ===========================================
void Tetris::_piece_spawn(void) {}
