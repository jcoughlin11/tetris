#include <cstdint>
#include <stdexcept>

#include <SDL3/SDL.h>

#include "SDL3/SDL_render.h"
#include "game.hpp"
#include "states.hpp"

// ===========================================
//             default constructor
// ===========================================
Game::Game() {
  SDL_SetAppMetadata("Tetris", "0.1", "com.example.tetris");

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    throw std::runtime_error("");
  }

  _window.reset(SDL_CreateWindow("Tetris", _GAME_HEIGHT, _GAME_WIDTH,
                                 SDL_WINDOW_RESIZABLE));

  if (!_window) {
    SDL_Quit();
    SDL_Log("Failed to create window: %s", SDL_GetError());
    throw std::runtime_error("");
  }

  _renderer.reset(SDL_CreateRenderer(_window.get(), NULL));

  if (!_renderer) {
    SDL_Quit();
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    throw std::runtime_error("");
  }

  _state = state_e::RUNNING;
  _done = false;
}

// ===========================================
//                destructor
// ===========================================
Game::~Game() { SDL_Quit(); }

// ===========================================
//              _events_handle
// ===========================================
void Game::_events_handle(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_EVENT_QUIT:
      _done = true;
      break;
    default:
      break;
    }
  }
}

// ===========================================
//                  _update
// ===========================================
void Game::_update(void) {
  // Move piece
  // Bool array indexed by scancodes. true if pressed, false if not
  const bool *keyStates{SDL_GetKeyboardState(NULL)};

  _tetris.update(keyStates);
}

// ===========================================
//                  _render
// ===========================================
void Game::_render(void) {
  // Set background color
  if (!SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255)) {
    SDL_Log("Failed to set background color, %s", SDL_GetError());
    throw std::runtime_error("");
  }

  // Draw background color
  if (!SDL_RenderClear(_renderer.get())) {
    SDL_Log("Failed to draw background, %s", SDL_GetError());
    throw std::runtime_error("");
  }

  // Set the line color
  if (!SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255)) {
    SDL_Log("Failed to set line color, %s", SDL_GetError());
    throw std::runtime_error("");
  }

  // Render the line
  float iPix{(20.0f * (float)_GAME_WIDTH / (float)_GAME_HEIGHT) - 10.f};

  if (!SDL_RenderLine(_renderer.get(), iPix, 0.0f, iPix, (float)_GAME_HEIGHT)) {
    SDL_Log("Failed to render line, %s", SDL_GetError());
    throw std::runtime_error("");
  }
}

// ===========================================
//                    run
// ===========================================
void Game::run(void) {
  while (!_done) {
    _events_handle();
    _update();
    _render();
  }
}
