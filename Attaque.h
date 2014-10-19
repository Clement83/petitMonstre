#if !defined (Attaque_H)
#define Attaque_H


#include "IGameObject.h"
#include <Gamebuino.h>

class Attaque : public IGameObject
{
  public:
    virtual void Init();
    virtual void Update(Gamebuino gb);
    virtual void Draw(Gamebuino gb);
};

#endif 