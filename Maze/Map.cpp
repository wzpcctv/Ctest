
#include "Map.h"

Map::Map() {};
Map::Map(int size) {
	m_iMap = new int[size];
	for (int i = 0; i < size; i++) {
		m_iMap[i] = type::EMPTY;
	}
}

//����xy��ȡindex
int Map::getIndex(int x, int y) {
	return y * WIDE + x;
}

//����xy��ȡ���ӵ�ֵ
int Map::cubType(int x, int y) {
	return m_iMap[getIndex(x, y)];
}

//����xy��ȡ����ָ��
int* Map::getCube(int x, int y) {
	return (m_iMap + getIndex(x, y));
}

//�ж�����Ƿ��ǿյ�
bool Map::isEmpty(int x, int y) {
	return (cubType(x, y) == type::EMPTY);
}

//�жϸ��ӵ�״̬
bool Map::check(int x, int y, int type) {
	return (cubType(x, y) == type);
}

//���ø���״̬
void Map::setCube(int x, int y, int type) {
	*getCube(x, y) = type;
}