#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;


template<class W>
struct EdgeNode
{
	int _srcIndex;
	int _dstIndex;
	const W& _w;

	EdgeNode<W>* next;

};

template<class V, class W, bool Direction = false>//���㣬Ȩֵ���Ƿ�������ͼ
class Graph
{
public:
	Graph(V* vertexs, int n) {
		vertexs.reserve(n);
		for (int i = 0; i < n; i++) {
			_vertexs.push_back(vertexs[i]);
			_vertexMap[vertexs[i]] = i;
		}

		_linkTable.resize(n, nullptr);

	}

	//��ö����±�
	int GetValue(const V& x) {
		auto it = _vertexMap.find(x);
		if (it != _vertexMap.end()) {
			return it->second;
		}
		else {
			return -1;
		}
	}

	//��ӱߵù�ϵ
	void AddEdge(const V& src, const V& dst, const W& w) {
		int srcIndex = GetValue(src);
		int dstIndex = GetValue(dst);

		EdgeNode* node = new EdgeNode;
		node->_srcIndex = srcIndex;
		node->_dstIndex = dstIndex;
		node->_w = w;

		//ͷ�嵽������
		node->next = _linkTable[srcIndex];
		_linkTable[srcIndex] = node;

		//���������ͼ
		if (Direction == false) {
			EdgeNode* node = new EdgeNode;
			node->_srcIndex = dstIndex;
			node->_dstIndex = srcIndex;
			node->_w = w;

			//ͷ�嵽������
			node->next = _linkTable[dstIndex];
			_linkTable[dstIndex] = node;
		}

	}

private:
	vector<V> _vertexs;  //���㼯��
	vector<EdgeNode<W>*> _linkTable;  //�ڽӱ�
	map<V, int> _vertexMap;  //�����ӳ�䣬��������±�
};