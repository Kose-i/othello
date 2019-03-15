#ifndef Game_hpp
#define Game_hpp

#include "Board.hpp"
#include "Computer.hpp"
#include "Hand.hpp"
#include "Player.hpp"

#include <array>
#include <fstream>
#include <map>
#include <memory>
#include <string>

class Game{

  private://param
    std::string file_path{"../config/detect_hand.txt"};
    std::ifstream ifs;
    std::shared_ptr<class Board> board;
    std::map<Board_env, std::unique_ptr<class Hand>> players;
    std::map<Board_env, std::string> player_name;

  private://function
    Game(Game&);
    int operator=(Game&);
    bool is_finish();

  public://function

    Game();
    ~Game();

    void init();
    void run();
    Board_env result();

};
#endif
