
#include <cassert>
#include <Corrade/Utility/Debug.h>
#include <Corrade/Interconnect/Receiver.h>
#include <Utils/Accumulator.h>

using namespace Corrade::Utility;
using namespace Corrade::Interconnect;
using namespace MOSP::Utils;

struct Trec : public Receiver
{
    void recv(double d)
    {
        Debug{} << formatString("Trec::recv({})", d);
    }
};

int main()
{
    StandardAccumulator acc;

    assert(acc.accumulatedDelta() == 0);
    assert(acc.referenceDelta() == 0);

    Debug{} << acc;

    acc.referenceDelta() = 10;

    while(acc.accumulatedDelta() < acc.referenceDelta())
    {
        Debug{} << acc.appendDelta(1);
        Debug{} << acc;
    }

    acc.reset();

    while(acc.accumulatedDelta() < acc.referenceDelta())
    {
        acc.appendDelta(0.75);
    }

    Debug{} << acc;

    StandardTriggeringAccumulator tacc(5);
    Trec trec;
    Corrade::Interconnect::connect(tacc, &StandardTriggeringAccumulator::triggered, trec, &Trec::recv);

    for(int i = 0; i < 10; i++)
        tacc.appendDelta(1);

    TimeAccumulator timeacc(5);
    timeacc.start();
    while(timeacc.left() > 0)
    {
        Debug{} << timeacc;
        Debug{} << timeacc.update();
    }

    return 0;
}
