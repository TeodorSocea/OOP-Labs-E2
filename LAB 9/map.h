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

public:
};