#ifndef Game_hpp
#define Game_hpp

#include ""
class Game{
  private:
    Game(Game&);
    operator=();
    bool is_finish();
  public:
    Game();
    ~Game();
    void init();
    void run();
};
#endif
