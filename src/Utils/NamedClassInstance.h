
#include <string>
#include <map>

namespace MOSP
{
    namespace Utils
    {
        template<class T>
        class NamedClassInstance
        {
            std::string m_name;
            static std::map<std::string, T*> m_nameIndex;
        public:
            const std::string& classInstanceName() const { return m_name; }
            bool setClassInstanceName(const std::string& name)
            {
                auto it = m_nameIndex.find(name);
                if (it != m_nameIndex.end())  return false;
                m_nameIndex.erase(m_name);
                m_nameIndex.insert(std::pair(name, dynamic_cast<T*>(this)));
                m_name = name;
                return true;
            }
            bool setClassInstanceName(const char *name)
            {
                std::string str(name);
                return setClassInstanceName(str);
            }
            virtual ~NamedClassInstance()
            {
                m_nameIndex.erase(m_name);
            }
        };

        template<class T>
        std::map<std::string, T*> NamedClassInstance<T>::m_nameIndex;
    }
}
