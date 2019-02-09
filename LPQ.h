#include <list>
  template <typename E, typename C>
  class ListPriorityQueue
{
  public:
    
    int size() const;				// number of elements
    bool empty() const;				// is the queue empty?
    void insert(const E& e);			// insert element
    const E& min() const;			// minimum element
    void removeMin();				// remove minimum
  private:
    
    std::list<E> L;				// priority queue contents
    C isLess;					// less-than comparator
  };
