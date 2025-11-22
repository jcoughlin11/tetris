#pragma once

#include <memory>

#include <SDL3/SDL.h>

#include "deleters.hpp"
#include "states.hpp"
#include "tetris.hpp"

// ===========================================
//                   Game
// ===========================================
class Game {
public:
  // Explicitly disable copying and moving
  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;
  Game(Game &&) noexcept = delete;
  Game &operator=(Game &&) noexcept = delete;

  Game();
  ~Game();
  void run(void);

private:
  void _events_handle(void);
  void _update(void);
  void _render(void);

  const int _GAME_WIDTH{640};
  const int _GAME_HEIGHT{480};

  // The second template parameter tells the unique_ptr what to call to handle
  // object destruction. Without it, it just does delete ptr.
  std::unique_ptr<SDL_Window, WindowDeleter> _window;
  std::unique_ptr<SDL_Renderer, RendererDeleter> _renderer;

  state_e _state;
  bool _done;

  Tetris _tetris;
};
