
#pragma once

#include <Corrade/Interconnect/Emitter.h>

namespace MOSP
{
    namespace Utils
    {
        template <typename T>
        class Accumulator
        {
            T m_accumulatedDelta{0};
            T m_referenceDelta{0};
        public:
            T accumulatedDelta() const { return m_accumulatedDelta; }
            T referenceDelta() const { return m_referenceDelta; }
            T& referenceDelta() { return m_referenceDelta; }
            T left() const { m_referenceDelta - m_accumulatedDelta; }
            T appendDelta(T d) {
                m_accumulatedDelta += d;
                return left();
            }
            void reset() { m_accumulatedDelta = 0; }
        };

        template <typename T>
        class TriggeringAccumulator : public Accumulator<T>, public Corrade::Interconnect::Emitter
        {
        public:
            Signal triggered(T dv)
            {
                return emit(&TriggeringAccumulator::triggered, dv);
            }
        };

        typedef Accumulator<double> StandardAccumulator;
        typedef TriggeringAccumulator<double> StandardTriggeringAccumulator;
    }
}
