
#include <map>

namespace MOSP
{
    namespace Utils
    {
        template<typename Key, class Class>
        class MapIndexEntry
        {
            Class& m_obj;
            Key m_key;
            std::map<Key, Class*>& m_index;
        public:
            bool valid() const {
                auto it = m_index.find(m_key);
                return it != m_index.end() && it->second == &m_obj;
            }
            Key indexValue() const { return m_key; }
            bool setIndexValue(Key key)
            {
                auto it = m_index.find(key);
                if (it != m_index.end())  return false;
                m_index.erase(m_key);
                m_index.insert(std::pair(key, &m_obj));
                m_key = key;
                return true;
            }
            MapIndexEntry(Class& v, std::map<Key, Class*>& i) : m_index{i}, m_obj{v} {}
            MapIndexEntry(Class& v, std::map<Key, Class*>& i, Key key) : m_index{i}, m_obj{v}
            {
                setIndexValue(key);
            }
            ~MapIndexEntry()
            {
                if (valid())  m_index.erase(m_key);
            }
        };
    }
}
