#include "controller.h"
#include "snake.h"

namespace SnakeGame
{
    bool Controller::HandleInput(Snake *snake, SDL_Point const & food, KeyStroke & pressedkey) 
  {
    switch (pressedkey)
    {
    case KeyStroke::keyUp:
      snake->ChangeDirection(Direction::kUp,
                      Direction::kDown);
      return true;

    case KeyStroke::keyDown:
      snake->ChangeDirection(Direction::kDown,
                      Direction::kUp);
      return true;

    case KeyStroke::keyLeft:
      snake->ChangeDirection(Direction::kLeft,
                      Direction::kRight);
      return true;

    case KeyStroke::keyRight:
      snake->ChangeDirection(Direction::kRight,
                      Direction::kLeft);
      return true;
    case KeyStroke::keyQuit:
      return false;
    case KeyStroke::none:
      return true;
    }
    return true;
  }

  VirtualController::VirtualController(std::size_t grid_width, std::size_t grid_height) : 
        routePlanner_(grid_width,grid_height) {
  }
  
  bool VirtualController::HandleInput(Snake *snake, SDL_Point const & food,KeyStroke & pressedkey)
  {

    if (KeyStroke::keyQuit == pressedkey){
      return false;
    }
  
    routePlanner_.run(snake,food);

    return true;
  }


}