#pragma once

class Tetris {
public:
  void update(const bool *);

private:
  void _piece_move(const bool *);
  void _gravity_apply(void);
  void _piece_lock(void);
  void _rows_clear(void);
  void _piece_spawn(void);
};
