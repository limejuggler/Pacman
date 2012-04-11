#include "HighScore.h"

HighScore::HighScore(){}
HighScore::HighScore(ID3DX10Font* font, ID3DX10Sprite* sprite)
{
	numberOfEntries = 10;
	this->sprite = sprite;
	this->font = font;

	entries = vector<string>(numberOfEntries);
	for( int i = 0; i < numberOfEntries; i++ )
	{
		entries.at(i) = "------------";
	}
	score = vector<int>(numberOfEntries);

	r = vector<RECT>(numberOfEntries);
	for(int i = 0; i < numberOfEntries - 1; i++)
	{
		r.at(i).top = (long)(200 + i * 30);
		r.at(i).bottom = (long)(230 + i * 30);
		r.at(i).left = (long)(SCREENWIDTH * .5f - 150);
		r.at(i).right = (long)(SCREENWIDTH * .5f + 150);
	}
	r.at(9).top = (long)(200 + 9 * 30);
	r.at(9).bottom = (long)(230 + 9 * 30);
	r.at(9).left = (long)(SCREENWIDTH * .5f - 159);
	r.at(9).right = (long)(SCREENWIDTH * .5f + 141);

	r2.left = (long)(SCREENWIDTH * .5f + 80);
	r2.right = (long)(SCREENWIDTH * .5f + 300);

	readFile(true);
}

void HighScore::saveFile()
{
	string name = fileName();
	fstream file(name, ios::out | ios::binary);
	for(int i = 0; i < numberOfEntries; i++)
	{
		file.write((const char*) &entries.at(i), sizeof(string) );
		file.write((const char*) &score.at(i), sizeof(int) );
	}
	file.close();
}

void HighScore::createFile()
{
	string t = "---------------";
	string name = fileName();
	fstream file(name, ios::out | ios::binary);
	for(int i = 0; i < numberOfEntries; i++)
	{
		file.write((const char*) &t, sizeof(string) );
		file.write((const char*) "0", sizeof(int) );
	}
	file.close();
}

void HighScore::readFile(bool checkForFaults) // when a player makes it to the highscore list, the entry is made to
	// make it easier for the player too se his/her score and entry. however, with this we must not check for a certain
	// string while the program is running
{
	string name = fileName();
	fstream file(name, ios::in | ios::binary);
	if(file.fail())
		createFile();
	for(int i = 0; i < numberOfEntries; i++ )
	{
		file.read((char*) &entries.at(i), sizeof(string));
		file.read((char*) &score.at(i), sizeof(int));
		/*if(checkForFaults && score.at(i) > 0 && entries.at(i) == "---------------")
			entries.at(i) = "Anonymous";*/
	}
	file.close();
}

string HighScore::fileName()
{
	char buffer[512];
	sprintf_s(buffer, "%d", listIndex);
	return "HighScore.hs";
}

//void HighScore::addEntry(string _entry)
//{
//	if(replaceAtIndex == -1)
//		return;
//
//	_entry = _entry != "" ? _entry.substr(0, 15) : "Anonymous";
//
//	entries.at(replaceAtIndex) = _entry;
//	saveFile();
//	readFile(false);
//}

//bool HighScore::checkAgainstHighScore(int _score)
//{
//	replaceAtIndex = -1;
//	for(int i = numberOfEntries - 1; i >= -1; i--)
//	{
//		if(i == -1 || (i > -1 && score.at(i) >= _score))
//		{
//			if(i + 1 < numberOfEntries)
//			{
//				replaceAtIndex = i + 1;
//				int tempScore;
//				string tempEntry;
//
//				for( int i = numberOfEntries - 1; i > replaceAtIndex; i-- )
//				{
//					tempEntry = entries.at(i - 1);
//					tempScore = score.at(i - 1);
//					entries.at(i) = tempEntry;
//					score.at(i) = tempScore;
//				}
//				score.at(replaceAtIndex) = _score;
//				entries.at(replaceAtIndex) = "---------------";
//
//				saveFile();
//				readFile(false);
//
//				return true;
//			}
//			else
//				return false;
//		}
//	}
//	replaceAtIndex = 0;
//	return true;
//}

//void HighScore::Draw(DxHandler* h)
//{
//	sprite->Begin(0);
//	char buffer[16];
//	for(int i = 0; i < numberOfEntries; i++)
//	{		
//		sprintf_s(buffer, "%d", i+1);
//
//		string entryText = (string)buffer + ". " + entries[i];
//
//		D3DXCOLOR col = i == replaceAtIndex ? D3DXCOLOR(0.524f, 0.227f, 0.227f, 1.0f) : D3DXCOLOR(0.324f, 0.027f, 0.027f, 1.0f);
//
//		font->DrawTextA(sprite, entryText.c_str(), -1, &r.at(i), DT_LEFT | DT_TOP, col);
//
//		sprintf_s(buffer, "%d", score[i]);
//
//		string scoreText = buffer;
//
//		r2.top = (long)(200 + i * 30);
//		r2.bottom = (long)(230 + i * 30);
//
//		font->DrawTextA(sprite, scoreText.c_str(), -1, &r2, DT_LEFT | DT_TOP , col);
//	}
//	sprite->Flush();
//	sprite->End();
//
//	h->getID3D10Device()->OMSetBlendState(NULL, 0, 0xffffffff);
//}
HighScore::~HighScore()
{
}
