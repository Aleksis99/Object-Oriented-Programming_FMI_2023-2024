
const int INIT_SIZE = 8;

template <class T>
class Queue 
{
	T* arr = nullptr;

	int capacity;
	int count;

	int head;
	int tail;
	
	void free();
	void copy(const Queue& other);
	void move(Queue&& other);

public:

	Queue();
	Queue(const Queue& other);
	Queue<T>& operator=(const Queue& other);
	~Queue();

	Queue<T>& operator=(Queue&& other);
	Queue(Queue&& other);

	int getCount() const;
	void resize(int capacity);
	bool isEmpty() const;

	T top() const;
	T pop();
	void push(const T& element);

};

template<class T>
void Queue<T>::free()
{
	delete[] arr;
}

template<class T>
void Queue<T>::copy(const Queue& other)
{
	count = other.count;
	capacity = other.capacity;

	this->arr = new T[capacity];
	int index = other.head;

	for (int i = 0; i < count; i++)
	{
		arr[i] = other.arr[index];
		index++;
		index = index % capacity;
	}

	head = 0;
	tail = 0;
	if (count > 0)
	{
		tail = count - 1;
	}
}

template<class T>
void Queue<T>::move(Queue&& other)
{
	arr = other.arr;
	count = other.count;
	head = other.head;
	tail = other.tail;

	other.arr = nullptr;
}

template<class T>
int Queue<T>::getCount() const
{
	return count;
}

template<class T>
void Queue<T>::resize(int capacity)
{
	if (capacity <= count)
	{
		return;
	}

	T* newArr = new T[capacity];
	int index = head;

	for (int i = 0; i < count; i++)
	{
		newArr[i] = arr[index];
		index++;
		index = index % this->capacity;
	}
	
	delete[] arr;

	this->capacity = capacity;
	arr = newArr;
	head = 0;
	tail = 0;

	if (count > 0)
	{
		tail = count - 1;
	}

}

template<class T>
Queue<T>::Queue()
{
	capacity = INIT_SIZE;
	count = 0;
	head = 0;
	tail = 0;

	arr = new T[capacity];
}

template<class T>
Queue<T>::Queue(const Queue& other)
{
	copy(other);
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<class T>
Queue<T>::~Queue()
{
	free();
}

template<class T>
Queue<T>& Queue<T>::operator=(Queue&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

template<class T>
Queue<T>::Queue(Queue&& other)
{
	move(std::move(other));
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return count == 0;
}

template<class T>
T Queue<T>::top() const
{
	if (isEmpty())
	{
		throw "Empty";
	}

	return arr[head];
}

template<class T>
T Queue<T>::pop()
{
	if (isEmpty())
	{
		throw "Empty";
	}

	int resultIndex = head;
	head++;
	head = head % capacity;
	count--;

	if (isEmpty())
	{
		head = 0;
		tail = 0;
	}

	return arr[resultIndex];
}

template<class T>
void Queue<T>::push(const T& element)
{
	if (count == capacity)
	{
		resize(capacity * 2);
	}

	if (!isEmpty())
	{
		tail++;
	}

	tail = tail % capacity;
	arr[tail] = element;
	count++;
}
