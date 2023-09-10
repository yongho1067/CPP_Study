﻿#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]

// DFS (Depth First Search) 깊이 우선 탐색
// BFS (Breadth Firsrt Search) 너비 우선 탐색

void CreateGrapgh_1()
{
	struct Vertex
	{
		vector<Vertex*> edges; // 간선목록
	};
	
	vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);

	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	
	v[3].edges.push_back(&v[4]);
	
	v[5].edges.push_back(&v[4]);

	// Q) 0번과 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}
}

void CreateGrapgh_2()
{
	// 연결된 목록을 따로 관리
	// adjacent[n] -> n번째 정점과 연결된 정점 목록

	vector<vector<int>> adjacent(6);

	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 4 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };
	
	// 정점이 100개
	// - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 ++)
	// - 페이스북 친구 -> 서로 빽빽하게 연결

	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}

	// STL
	vector<int>& adj = adjacent[0];
	bool connected2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}

void CreateGrapgh_3()
{
	struct Vertex
	{
		
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// 
	// [X][0][X][0][X][X]
	// [0][X][0][0][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][0][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][0][X]

	// 읽는 방법 : adjacent[from][to]
	// 행렬을 이용한 그래프 표현 (2차원 배열)
	// 메모리 소모가 심하지만, 빠른 접근이 가능하다
	// (간선이 많은 경우 이점이 있다)

	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// 정점이 100개
	// - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 ++)
	// - 페이스북 친구 -> 서로 빽빽하게 연결

	bool connected = adjacent[0][3];

	vector<vector<int>> adjacent2 =
	{
		vector<int> { -1, 15, -1, 35, -1, -1},
		vector<int> { 15, -1, 5, 10, -1, -1},
		vector<int> { -1, -1, -1, -1, -1, -1},
		vector<int> { -1, -1, -1, -1, 5, -1},
		vector<int> { -1, -1, -1, -1, -1, -1},
		vector<int> { -1, -1, -1, -1, 5, -1},
	};

	adjacent2[0][3];

}

int main()
{
	CreateGrapgh_1();
	CreateGrapgh_2();
	CreateGrapgh_3();
}

