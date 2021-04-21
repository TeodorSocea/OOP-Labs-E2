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
    };
    class tie
    {
    public:
        K key;
        V value;
        int index;
        tie(K _key, V _value, int _index) : key(_key), value(_value), index(_index) {}
    };
    class MapIterator
    {
    private:
        MapEntry *MapEntriesClone;
        int index;

    public:
        MapIterator(const MapEntry *MapEntries, int _index) : MapEntriesClone(MapEntries), index(_index) {}
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
    V &operator[](K key)
    {
        for (int i = 0; i < size; i++)
        {
            if (MapEntries[i].first == key)
            {
                return MapEntries[i].second;
            }
        }
        if (size == count)
        {
            size *= 2;
            MapEntry *newMapEntries = new MapEntry[size];
            memcpy(newMapEntries, MapEntries, sizeof(MapEntries));
            delete[] MapEntries;
            MapEntries = newMapEntries;
        }
        MapEntries[count++].first = key;
        return MapEntries[count - 1].second;
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