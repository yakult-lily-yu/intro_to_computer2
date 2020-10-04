#pragma once
#ifndef maze_h
#define maze_h
#include<vector>
#include<string>

using namespace std;

class maze
{
public:
	static vector<vector<string>> mydata;
	static int treasure_count;
	static int start_x;
	static int start_y;
	//void start( int start_x, int start_y);
	void readmap(string filename);
	bool move(int x, int y);
	//int* find_start(vector<vector<string>> data);
	void find_start(vector<vector<string>> data);
	void printmap(vector<vector<string>> data);

private:
	bool valid(int x, int y);
};

#endif // !read_file

