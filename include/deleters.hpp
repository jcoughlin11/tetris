#pragma once

#include <SDL3/SDL.h>

// ===========================================
//               WindowDeleter
// ===========================================
class WindowDeleter {
public:
  void operator()(SDL_Window *window) const noexcept {
    if (window) {
      SDL_DestroyWindow(window);
    }
  }
};

// ===========================================
//               RendererDeleter
// ===========================================
class RendererDeleter {
public:
  void operator()(SDL_Renderer *renderer) const noexcept {
    if (renderer) {
      SDL_DestroyRenderer(renderer);
    }
  }
};
