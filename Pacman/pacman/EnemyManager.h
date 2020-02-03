#include "Units.h"

enum class GhostsState{
  Chase,
  Scatter,
  Frightened
};

class EnemyManager{
public:

private:
  GhostsState curState = GhostsState::Scatter;
  
}
