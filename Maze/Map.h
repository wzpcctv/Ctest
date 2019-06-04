#pragma once

#ifndef MAP_H
#define MPA_H

#define WIDE 30
#define HIGH 30

class Map {
public:
	enum type { EMPTY,WALL };
	Map();
	Map(int size);

	//����xy��ȡindex
	int getIndex(int x, int y);

	//����xy��ȡ���ӵ�ֵ
	int cubType(int x, int y);

	//����xy��ȡ����ָ��
	int* getCube(int x, int y);

	//�ж�����Ƿ��ǿյ�
	bool isEmpty(int x, int y);

	//�жϸ��ӵ�״̬
	bool check(int x, int y, int type);

	//���ø���״̬
	void setCube(int x, int y, int type);

private:
	int* m_iMap;
	int m_iNum;
};

#endif