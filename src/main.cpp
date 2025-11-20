#include <stdexcept>

#include "game.hpp"

int main(void) {

  try {
    Game game{};
    game.run();
  } catch (std::runtime_error) {
    return 1;
  }

  return 0;
}
