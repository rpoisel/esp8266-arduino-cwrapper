#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stddef.h>
#include <stdint.h>

template<class T, size_t capacity>
class RingBuffer
{
public:
  void push_back(T elem);
  T* pop_front(void);
  bool available(void) const;

private:
  T ring[capacity];
  size_t count;
  size_t headIdx;
  size_t tailIdx;
};

template<class T, size_t capacity>
void RingBuffer<T, capacity>::push_back(T elem)
{
  ring[headIdx] = elem;
  headIdx = headIdx == capacity - 1 ? 0 : headIdx + 1;
  if (count == capacity)
  {
    tailIdx = tailIdx == capacity - 1 ? 0 : tailIdx + 1;
    return;
  }
  count++;
}

template<class T, size_t capacity>
T* RingBuffer<T, capacity>::pop_front(void)
{
  if (!available())
  {
    return nullptr;
  }
  T* result = ring + tailIdx;
  tailIdx = tailIdx == capacity - 1 ? 0 : tailIdx + 1;
  count--;
  return result;
}

template<class T, size_t capacity>
bool RingBuffer<T, capacity>::available(void) const
    {
  return count > 0;
}

#endif /* RING_BUFFER_H_ */
