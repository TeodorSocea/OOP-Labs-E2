template <class K, class V>
class Map
{
private:
    class MapEntry
    {
    private:
        K first;
        V second;

    public:
        MapEntry(K key, V value) : first(key), second(value) {}
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
};