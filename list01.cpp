#include<iostream>
using namespace std;

//˫���ͷѭ������
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

/*��Ϊlistʱ˫�����������ڲ���Ĳ�ֻ�����ݣ�����ǰ��ָ�룬ֱ�ӽ����û����
�������������洢�ռ䲻�������ģ�++��--��������ǰ/��ƫ��һ���Ĵ�С������һ�������������ռ������û�������
���Խ�ԭ��ָ̬����з�װ���������ʹ����ʽ��ָ����ȫ��ͬ��������Զ�������б���ʵ�����·�����
1. ָ����Խ����ã������������б�������operator * ()
2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
����operator--() / operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫��������
����ǰ �ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����--
4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator == ()��operator != ()*/
template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef	ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;

	ListIterator(Node* node)
		:_node(node)
	{}

	//�����ã� *iterator --->  ��ȡ�ڵ�value
	Ref operator*()
	{
		return _node->_value;
	}

	// ָ��->��Ա,һ��listԪ��Ϊ�Զ�������ʱ��
	Ptr operator->()
	{
		return &_node->_value;
	}

	// ++: �ƶ�����һ��Ԫ�ص�λ��
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

	//����ͨ������const���η�����const������
	typedef ListIterator<T, const T&, const T*> const_iterator;

	iterator begin() 
	{
		//��һ��Ԫ�ص�λ��
		return iterator(_header->_next);
	}

	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return iterator(_header);
	}

	const_iterator begin() const
	{
		//��һ��Ԫ�ص�λ��
		return const_iterator(_header->_next);
	}

	const_iterator end() const
	{
		//���һ��Ԫ�ص���һ��λ��
		return const_iterator(_header);
	}

	//���캯��
	List()
		:_header(new Node)
	{
		//����ѭ���ṹ
		_header->_next = _header->_prev = _header;
	}

	//���뺯��insert
	void insert(iterator pos, const T& val)
	{
		Node* cur = new Node(val);
		//posǰ����
		Node* node = pos._node;
		Node* prev = node->_prev;

		prev->_next = cur;
		cur->_prev = prev;

		cur->_next = node;
		node->_prev = cur;
	}

	//ɾ���ᵼ�µ�����ʧЧ
	//����ֵ�� ��ɾ������Ԫ�ص���һ��Ԫ��λ��
	iterator erase(iterator pos)
	{
		//����ɾ��ͷ��㣨_header)
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

	//�������Ԫ�ظ���
	size_t size() const
	{
		size_t count = 0;
		for (const auto& e : *this)
			++count;
		return count;
	}

	//����
	~List()
	{
		if (_header)
		{
			clear();
			delete _header;
			_header = nullptr;
		}
	}

	//������з�ͷ��㺯��
	void clear()
	{
		Node* cur = _header->_next;
		while (cur != _header)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		//���¹���ѭ���ṹ
		_header->_next = _header->_prev = _header;
	}

	List(const List<T>& lst)
		:_header(new Node)
	{
		_header->_next = _header->_prev = _header;
		//���������Ԫ��
		for (const auto& e : lst)
			pushBack(e);
	}
	//�ִ�д��
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



