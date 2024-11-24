#include "animations.h"

void Animations::pushBack(std::function<void()> &&animation)
{
    animations.enqueue(animation);
}

void Animations::show()
{
    if (not animations.isEmpty() && not runnig) {
        runnig = true;
        animations.dequeue()();
    }
}

void Animations::next()
{
    runnig = false;
    show();
}
