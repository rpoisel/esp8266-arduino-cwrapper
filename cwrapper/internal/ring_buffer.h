#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stddef.h>
#include <stdint.h>

template<class T>
class RingBuffer
{
public:
  RingBuffer(size_t buffer_size);
  ~RingBuffer(void);

  void push_back(T elem);
  T* pop_front(void);
  bool available(void) const;

private:
  T* ring;
  const size_t capacity_;
  size_t count;
  size_t headIdx;
  size_t tailIdx;
};

template<class T>
RingBuffer<T>::RingBuffer(size_t capacity)
:
    capacity_(capacity),
        count(0)
            , headIdx(0)
            , tailIdx(0)
{
  ring = new T[capacity];
}

template<class T>
RingBuffer<T>::~RingBuffer(void)
{
  delete[] ring;
}

template<class T>
void RingBuffer<T>::push_back(T elem)
{
  ring[headIdx] = elem;
  headIdx = headIdx == capacity_ - 1 ? 0 : headIdx + 1;
  if (count == capacity_)
  {
    tailIdx = tailIdx == capacity_ - 1 ? 0 : tailIdx + 1;
    return;
  }
  count++;
}

template<class T>
T* RingBuffer<T>::pop_front(void)
{
  T* result;
  if (count == 0)
  {
    return nullptr;
  }
  result = ring + tailIdx;
  tailIdx = tailIdx == capacity_ - 1 ? 0 : tailIdx + 1;
  count--;
  return result;
}

template<class T>
bool RingBuffer<T>::available(void) const
    {
  return count > 0;
}

#endif /* RING_BUFFER_H_ */
