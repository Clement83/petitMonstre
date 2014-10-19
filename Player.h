#if !defined (Player_H)
#define Player_H

#include "IGameObject.h"
#include <Gamebuino.h>

class Player : public IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
};

#endif