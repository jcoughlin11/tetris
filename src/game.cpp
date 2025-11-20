#include <stdexcept>

#include <SDL3/SDL.h>

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
void Game::_update(void) {}

// ===========================================
//                  _render
// ===========================================
void Game::_render(void) {}

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
