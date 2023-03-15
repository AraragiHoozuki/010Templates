//------------------------------------------------
//--- 010 Editor v10.0 Binary Template
//
//   File: Enums.h
//   Author: Georges Zebit(https://github.com/AraragiHoozuki)
//   History: 
//------------------------------------------------

typedef struct {
    int Length;
	if (Length > 0)
    	wchar_t Content[Length/2];
} LString<read=(Length>0?Content:"NULL")>;

typedef struct
{
	int Size;
	int Version;
	int _Separator;
	byte _Padding[24];
} BlockInfo;



typedef struct {
    byte Version;
    int Hash;
} Chapter;

typedef struct {
	int ContentsMounted : 1;
	int FinishedSetupMap : 1;
	int __Casual : 1;
	int __Phoenix : 1;
	int EncountMap : 1;
	int ContinuedMap : 1;
	int FixedGrow : 1;
	int Completed : 1;
	int TemporarySaved : 1;
	int TemporaryLoaded : 1;
	int NetLoginOnce : 1;
	int RestartMap : 1;
	int RecollectionMap : 1;
	int IgnoreKizuna : 1;
	int EvilCompleted : 1;
	int Empty : 1;
} UserDataStatus;


typedef struct {
    byte Version;
    byte HasGenderQ;
    if (HasGenderQ != 0)
        LString HeroName;
        Gender HeroGender;
        Language Lang;
        byte BirthMonth;
        byte BirthDay;
} UnitEdit;

typedef struct
{
    LString Key;
    byte StringQ;
    if (StringQ == 1)
        LString Value;
    else
    {
        int Value;
    }
} GameVariable<read=(Key.Content)>;

typedef struct
{
	int Zero;
	uint Seed1Ptr;
	uint Seed1[3];
} RandomSeed;

typedef struct
{
	float x;
	float y;
	float z;
} Vector3;

typedef struct {
    int Version;
    int GameVersion;
    UserDataStatus Status;
    Chapter CurrentChapter;
    Chapter NextChapter;
    Sequences Sequence<comment="HeroPlace?">;
    Difficulty GameDifficulty;
    Difficulty EvilDifficulty;
    GameMode Mode;
    ushort Turn;
    int ContentsIndex;
    uint64 Identifier;
    float PlayTime<comment="Seconds">;
    byte ChallengeRoute<comment="連戦_ルート">;
    byte ChallengeStage<name="">;
    UnitEdit HeroInfo;
    int CRC32CheckSum<format=hex>;
} SaveDataHeader;

typedef struct {
    BlockInfo Info;
    byte Buffer[Info.Size - 36];
} BufferBlock;

typedef struct {
    BlockInfo Info;
    UserDataStatus Status;
    Sequences Sequence;
    GameMode Mode;
    Difficulty GameDifficulty;
    Difficulty EvilDifficulty;
    Chapter UserDataChapter;
    int ContentsIndex;
    struct {
        BlockInfo Info;
        int Count;
        GameVariable Var[Count]<optimize=false>;
    } GameVariables;
    int Gold;
    int Progress;
    int TrainingCount;
    int ArenaCount;
    int UnitInfoMode;
    LString GmapSpot;
    int PieceOfBond;
    int TotalPieceOfBond;
    LString MascotName;
    uint64 Identifier;
    struct {
        byte _Unknown;
        RandomSeed Seeds[6];
    } Random;
    struct {
        BlockInfo Info;
        LString FieldBgm1;
        LString FieldBgm2;
        LString FieldBgm3;
        LString WarSituationStateName;
    } Sound;
    struct {
        BlockInfo Info;
        float GmapCameraDistance;
        int GmapEcountsCount;
        struct {
            LString ModGmapSpot;
            struct {
                BlockInfo Info;
                LString Ejid;
                byte Empty;
                GmapSpotEncountPersonType Type;
                byte Rank;
                byte Cycle;
                byte PlayerDispos;
                byte EnemyDispos;
                RandomSeed Seed;
                EncountUnitDataRareType RareType;
                byte ExpRareCount;
                byte GoldRareCount;
                LString LeaderJid;
                Gender LeaderGender;
            } EncountMob;
        } GmapEcounts[GmapEcountsCount]<optimize=false>;
        int64 LastUpdateTime;
        byte EncountCounters[3];
        GmapMode Mode;
        LString NewSpotGod;
        LString NewSpotEvil;
    } UserGmapData;
    struct {
        BlockInfo Info;
        byte Count;
        struct {
            LString Cid;
            LString MvpPid;
            LString MvpJid;
            LString MvpGid;
            float ClearTime;
            int ClearTurn;
        } ChapterRecords[Count]<read=(Cid.Content),optimize=false>;
    } ChapterRecordData;
    struct {
        BlockInfo Info;
        byte Stream[Info.Size - 44];
        time64_t SaveTime;
    } MapEditData;
    struct {
        BlockInfo Info;
        FSkip(Info.Size - 36);
    } MapHistoryData;
    struct {
        byte _Padding;
        int Count;
        struct {
            uint64 DataId;
            byte PlayerIndex;
            byte AwardedQ;
        } EnteredBattle[Count]<optimize=false>;
    } RelayUserData;
    struct {
        BlockInfo Info;
        short Rate;
        uint64 DataId;
    } VersusUserData;
    struct {
        BlockInfo Info;
        Vector3 LastPosition;
        float LastDirectionY;
        int CameraSpeed;
        byte MinimapRotateQ;
        float CameraZoomParam;
        int MapMode;
    } UserHubData;
    struct {
        BlockInfo Info;
        FSkip(Info.Size - 36);
    } TurnSaveData;
} GameUserData;

typedef struct(char name[]) {
    int Offset;
    local int pos = FTell();
    FSeek(Offset);
    int Hash<format=hex>;
    if (name == "User")
        GameUserData User;
    else if (name == "CheckSum")
        int CRC32CheckSum<format=hex>;
    else
    {
        BufferBlock Buffer_WIP;
    }
    FSeek(pos);
} Tag;