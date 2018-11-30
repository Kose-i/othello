#ifndef Game_hpp
#define Game_hpp

#include "Board.hpp"
#include "Hand.hpp"
#include "Computer.hpp"
#include "Player.hpp"

#include <fstream>
#include <string>
#include <map>

class Game{

  private://param
    std::string file_path{"../config/detect_hand.txt"};
    std::ifstream ifs;
    std::shared_ptr<class Board> board;
    std::map<Board_env, class Hand*> players;

  private://function
    Game(Game&);
    int operator=(Game&);
    bool is_finish();

  public://function
    Game();

    ~Game();
    void init();
    void run();

};
#endif
