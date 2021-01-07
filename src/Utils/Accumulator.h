
#pragma once

#include <Corrade/Interconnect/Emitter.h>
#include <Corrade/Utility/FormatStl.h>
#include <Corrade/Utility/DebugStl.h>
#include <Corrade/Utility/Debug.h>
#include <Magnum/Timeline.h>

namespace MOSP
{
    namespace Utils
    {
        template <typename T>
        class Accumulator
        {
        protected:
            T m_accumulatedDelta{0};
            T m_referenceDelta{0};
        public:
            Accumulator(T rd = 0) { m_referenceDelta = rd; }
            T accumulatedDelta() const { return m_accumulatedDelta; }
            T referenceDelta() const { return m_referenceDelta; }
            T& referenceDelta() { return m_referenceDelta; }
            T left() const { return m_referenceDelta - m_accumulatedDelta; }
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
            TriggeringAccumulator(T rd) : Accumulator<T>(rd) {}
            Signal triggered(T dv)
            {
                return emit(&TriggeringAccumulator::triggered, dv);
            }
            T appendDelta(T d)
            {
                T lft = Accumulator<T>::appendDelta(d);
                if (lft <= 0)
                {
                    triggered(Accumulator<T>::m_accumulatedDelta);
                    Accumulator<T>::reset();
                }
                return lft;
            }
        };

        typedef Accumulator<double> StandardAccumulator;
        typedef TriggeringAccumulator<double> StandardTriggeringAccumulator;

        class TimeAccumulator : public StandardAccumulator, public Magnum::Timeline
        {
        public:
            TimeAccumulator(double rd) : StandardAccumulator(rd) {}
            double update()
            {
                nextFrame();
                return appendDelta(previousFrameDuration());
            }
        };

        class TriggeringTimeAccumulator : public StandardTriggeringAccumulator, public Magnum::Timeline
        {
        public:
            TriggeringTimeAccumulator(double rd) : StandardTriggeringAccumulator(rd) {}
            double update()
            {
                nextFrame();
                return appendDelta(previousFrameDuration());
            }
        };

        template<typename T>
        Corrade::Utility::Debug& operator<<(Corrade::Utility::Debug& out, const Accumulator<T>& acc)
        {
            out << Corrade::Utility::formatString("Accumulator{{{}, {}}}", acc.accumulatedDelta(), acc.referenceDelta());
            return out;
        }
    }
}
