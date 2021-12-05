#pragma once
typedef struct {
	int x;
	int y;
}Point;
int compare_points(Point a, Point b) {
	if (a.x == b.x)
		return a.y - b.y;
	return a.x - b.x;
}
