#include <cstring>
#include <tuple>
template <class K, class V>
class Map
{
private:
    class MapEntry
    {
    public:
        K first;
        V second;
        MapEntry(K key, V value) : first(key), second(value) {}
        MapEntry() = default;
        void operator=(V value)
        {
            second = value;
        }
    };
    class Tie
    {
    public:
        K key;
        V value;
        int index;
        Tie(K _key, V _value, int _index) : key(_key), value(_value), index(_index)
        {
            printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
        }
    };
    class MapIterator
    {
    private:
        MapEntry *MapEntriesClone;
        int index;

    public:
        MapIterator(MapEntry *MapEntries, int _index) : MapEntriesClone(MapEntries), index(_index) {}
        MapIterator(int _index) : MapEntriesClone(nullptr), index(_index) {}
        bool operator!=(const MapIterator &_MapIterator)
        {
            if (index != _MapIterator.index)
                return true;
            return false;
        }
        void operator++()
        {
            ++index;
        }
        auto operator*()
        {
            return std::tie(MapEntriesClone[index].first, MapEntriesClone[index].second, index);
        }
    };
    // map class members
    MapEntry *MapEntries;
    int count;
    int size;

public:
    Map()
    {
        count = 0;
        size = 1;
        MapEntries = new MapEntry[size];
    }
    ~Map()
    {
        delete[] MapEntries;
    }
    int Count()
    {
        return count;
    }
    MapEntry &operator[](K key)
    {
        for (int i = 0; i < size; i++)
        {
            if (MapEntries[i].first == key)
            {
                return MapEntries[i];
            }
        }
        if (size == count)
        {
            size *= 2;
            MapEntry *newMapEntries = new MapEntry[size];
            memcpy(newMapEntries, MapEntries, count * sizeof(MapEntry));
            delete[] MapEntries;
            MapEntries = newMapEntries;
        }
        MapEntries[count].first = key;
        count++;
        return MapEntries[count - 1];
    }
    bool Get(const K &key, V &value)
    {
        for (int i = 0; i < count; i++)
        {
            if (MapEntries[i].first == key)
            {
                value = MapEntries[i].second;
                return true;
            }
        }
        return false;
    }
    MapIterator begin()
    {
        return MapIterator(MapEntries, 0);
    }
    MapIterator end()
    {
        return MapIterator(count);
    }
};