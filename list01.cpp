#include<iostream>
using namespace std;

//双向带头循环链表
template <class T>
struct ListNode
{
	T _value;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_value(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

/*因为list时双向链表，其内部存的不只有数据，还有前后指针，直接解引用会出错
还有它的物理存储空间不是连续的，++，--操作是向前/后偏移一定的大小，而下一个紧挨的物理空间可能是没有申请的
所以将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
1. 指针可以解引用，迭代器的类中必须重载operator * ()
2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
至于operator--() / operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可
以向前 移动，所以需要重载，如果是forward_list就不需要重载--
4. 迭代器需要进行是否相等的比较，因此还需要重载operator == ()与operator != ()*/
template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef	ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;

	ListIterator(Node* node)
		:_node(node)
	{}

	//解引用： *iterator --->  获取节点value
	Ref operator*()
	{
		return _node->_value;
	}

	// 指针->成员,一般list元素为自定义类型时用
	Ptr operator->()
	{
		return &_node->_value;
	}

	// ++: 移动到下一个元素的位置
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node != it._node;
	}

	Node* _node;
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;

	typedef ListIterator<T, T&, T*> iterator;

	//不能通过添加const修饰符定义const迭代器
	typedef ListIterator<T, const T&, const T*> const_iterator;

	iterator begin() 
	{
		//第一个元素的位置
		return iterator(_header->_next);
	}

	iterator end()
	{
		//最后一个元素的下一个位置
		return iterator(_header);
	}

	const_iterator begin() const
	{
		//第一个元素的位置
		return const_iterator(_header->_next);
	}

	const_iterator end() const
	{
		//最后一个元素的下一个位置
		return const_iterator(_header);
	}

	//构造函数
	List()
		:_header(new Node)
	{
		//构建循环结构
		_header->_next = _header->_prev = _header;
	}

	//插入函数insert
	void insert(iterator pos, const T& val)
	{
		Node* cur = new Node(val);
		//pos前插入
		Node* node = pos._node;
		Node* prev = node->_prev;

		prev->_next = cur;
		cur->_prev = prev;

		cur->_next = node;
		node->_prev = cur;
	}

	//删除会导致迭代器失效
	//返回值： 被删除掉的元素的下一个元素位置
	iterator erase(iterator pos)
	{
		//不能删除头结点（_header)
		if (pos != end())
		{
			Node* node = pos._node;
			Node* prev = node->_prev;
			Node* next = node->_next;

			delete node;

			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		return pos;
	}

	void pushBack(const T& val)
	{
		insert(end(), val);
	}

	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	void popBack()
	{
		erase(--end());
	}

	void popFront()
	{
		erase(begin());
	}

	//获得链表元素个数
	size_t size() const
	{
		size_t count = 0;
		for (const auto& e : *this)
			++count;
		return count;
	}

	//析构
	~List()
	{
		if (_header)
		{
			clear();
			delete _header;
			_header = nullptr;
		}
	}

	//清空所有非头结点函数
	void clear()
	{
		Node* cur = _header->_next;
		while (cur != _header)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		//重新构建循环结构
		_header->_next = _header->_prev = _header;
	}

	List(const List<T>& lst)
		:_header(new Node)
	{
		_header->_next = _header->_prev = _header;
		//深拷贝，插入元素
		for (const auto& e : lst)
			pushBack(e);
	}
	//现代写法
	List<T>& operator=(List<T> lst)
	{
		swap(_header, lst._header);
		return *this;
	}

private:
	Node* _header;
};

//template <class T>
//void printList(const List<T> lst)
//{
//	List<T>::const_iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		//*it = T();
//		++it;
//	}
//	cout << endl;
//}

template <class T>
void printListFor(const List<T>& lst)
{
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test() {
	List<int> lst;
	lst.insert(lst.begin(), 1);
	printListFor(lst);
	lst.pushBack(2);
	printListFor(lst);
	lst.pushFront(0);
	printListFor(lst);
	List<int>::iterator it = ++lst.begin();
	lst.insert(it, -1);
	printListFor(lst);
	it = lst.erase(it);
	printListFor(lst);
	cout << *it << endl;
}

int main() {
	test();
	return 0;
}




