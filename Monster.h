#if !defined (Monster_H)
#define Monster_H

#include "IGameObject.h"
#include <Gamebuino.h>

class Monster : public IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
};


#endif
