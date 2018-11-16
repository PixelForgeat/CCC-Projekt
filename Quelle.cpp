#include <iostream>
#include <string>
#include "CCCParser.h"
#include "List.h"

using namespace std;

class Tile{
public:
	Tile(int xi,int yi,int buildingheighti) {
		x = xi;
		y = yi;
		buildingheight = buildingheighti;
	}
	Tile(){}
	int x, y, buildingheight;
	int alreadychecked=0;
	int id=-1;
};

int main(int Kot)
{
	List<string> lStringParts;
	List<string> lAllParts;
	List<int> lIntParts;
    CCCParser::parseFileInput("level2_0.in", lStringParts, lIntParts, lAllParts );

	// CCC code start
	int height, width = 0;
	int ids = 0;

	height = lIntParts[0];
	width = lIntParts[1];
	lIntParts.remove(1);
	lIntParts.remove(0);

	List<int> output;
	List<Tile> tiles;

	List<int> indexes;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (lIntParts[i*height + j] > 0) {
				tiles.append(Tile(j,i,lIntParts[i*height + j]));
			}
		}
	}

	/*for (tiles.begin();tiles<tiles.Length();tiles++) {
		cout << tiles.currentElement().x << " " << tiles.currentElement().y << " " << tiles.currentElement().buildingheight << " " << "\n";
	}
	*/

	for (int i=0;i < tiles.Length(); i++) {
		if (tiles[i].alreadychecked == 0) {
			tiles[i].alreadychecked = 1;

			for (int j = 0, found=0; j <= i; j++) {

				if (tiles[i].x == tiles[j].x + 1 && tiles[i].y == tiles[j].y) {
					found++;
				}else if (tiles[i].y == tiles[j].y + 1 && tiles[i].x == tiles[j].x) {
					found++;
				}
				if (found > 0) {
					found = 0;
					tiles[i].id = tiles[j].id;
					break;
				} else if (j + 1 == i && found == 0)
				{
					tiles[i].id = ids++;
					break;
				}
			}
		}
	}
	
	for (tiles.begin();tiles<tiles.Length();tiles++) {
		cout << tiles.currentElement().x << " " << tiles.currentElement().y << " " << tiles.currentElement().buildingheight << " " << tiles.currentElement().id << "\n";
	}

	for (int i=0; i<tiles.Length(); i++) {
		if (tiles[i].id+1 > indexes.Length()) {
			indexes.append(0);
		}
		indexes[tiles[i].id]++;
	}
	
	for (int i=0; i < indexes.Length(); i++) {
		cout << indexes[i] << " ";
	}

	// CCC code end
	cin.get();
	CCCParser::printToFile("output.txt", output);
	return Kot;
}
