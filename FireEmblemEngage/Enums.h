
//UserData
enum<byte> Difficulty 
{
    Normal,
    Hard,
    Lunatic
};

enum<byte> Sequences
{
    //None = 0,
    ChapterSave = 1,
    Sortie = 2,
    Map = 3,
    Hub = 4,
    Kizuna = 5,
    Gmap = 6,
    Chapter = 7,
    //Num = 8
};

enum<byte> GameMode
{
    Casual,
    Classic,
    Phoenix
};

enum<byte> Gender
{
    //None = 0,
    Male = 1,
    Female = 2,
    Other = 3,
    //Num = 4
};

enum<byte> Language
{
	JP_Japanese = 0,
	US_English = 1,
	US_French = 2,
	US_Spanish = 3,
	EU_English = 4,
	EU_French = 5,
	EU_Spanish = 6,
	EU_German = 7,
	EU_Italian = 8,
	CN_Traditional = 9,
	CN_Simplified = 10,
	KR_Korean = 11,
	Max = 12
};


enum GameSaveDataTypes
{
	//None = 0,
	Global = 1,
	__Chapter = 2,
	__Temporary = 3,
	__Debug = 4,
	Auto = 5,
	Manual = 6
	//Num = 7,
};