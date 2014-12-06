#include <HighScore.hpp>

using namespace uth;

Highscore::Highscore()
{
	FileManager file;
	if (file.OpenFile("testfile.lol", uth::FileManager::Location::INTERNAL))
	{
		auto data = file.ReadBinary();
		WriteLog("%d\n", sizeof(m_scores));
		memcpy((void*)m_scores, data.ptr(), sizeof(m_scores));
		file.CloseFile();
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			m_scores[i].score = i * pow(10, i);
			for (int j = 0; j < 3; j++)
				m_scores[i].name[i] = 'A';
		}
	}
}

Highscore::~Highscore()
{
	BINARY_DATA data(m_scores,sizeof(m_scores));
	FileManager file;
	file.OpenFile("testfile.lol", uth::FileManager::Location::INTERNAL, true);
	file.WriteBinary(data);

	file.CloseFile();
}


