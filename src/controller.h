#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "route_planner.h"

#include "SDL.h"
namespace SnakeGame
{
    class ControllerBase {
    public:
        ControllerBase() = default;
        virtual ~ControllerBase() = default;
        ControllerBase(const ControllerBase & other) = default;
        ControllerBase(ControllerBase && other) = default;
        ControllerBase& operator=(const ControllerBase & other) = default;
        ControllerBase& operator=(ControllerBase && other) = default;

        virtual bool HandleInput(Snake *snake, SDL_Point const & food, KeyStroke & pressedkey)  = 0;

    };

    class Controller : public ControllerBase
    {
    public:
        bool HandleInput(Snake *snake, SDL_Point const & food, KeyStroke & pressedkey)  override;

    };

    class VirtualController : public ControllerBase {
    public:
        VirtualController(std::size_t grid_width, std::size_t grid_height);
        bool HandleInput(Snake *snake, SDL_Point const & food, KeyStroke & pressedkey)  override;
    private:
        RoutePlanner routePlanner_;        
    
    };
}
#endif