//------------------------------------------------
//--- 010 Editor Binary Template
//
//   File: Struct.h
//   Author: Georges Zebit(https://github.com/AraragiHoozuki)
//   Purpose: Analyze Fe Engage Save Data
//   History: 
//------------------------------------------------

typedef struct {
    int Length;
	if (Length > 0)
    	wchar_t Content[Length/2];
} LString<read=(Length>0?Content:"NULL")>;

wchar_t[] ReadLString(LString &ls) {
    if (ls.Length > 0)
        return ls.Content;
    else {
        return "NULL";
    }
}

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
    if (HasGenderQ != 0) {
        LString HeroName;
        Gender HeroGender;
        Language Lang;
        byte BirthMonth;
        byte BirthDay;
    }
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
    ushort NotEmptyQ<format=hex>;
    if (NotEmptyQ == 0xEFCD)
        int SkillHash;
} SkillData;

typedef struct {
    int Version;
    byte ExistsQ;
    if (ExistsQ == 1)
    {
        SkillData ItemData;
        ubyte Endurance;
        ubyte RefineLevel;
        uint Flags;
        SkillData EngraveData;
    }
} UnitItem;

typedef struct  {
	uint64 Fixed : 1;
	uint64 MoveNotAllow : 1;
	uint64 MustSortie : 1;
	uint64 NeverSortie : 1;
	uint64 DontPosChange : 1;
	uint64 DangerShowing : 1;
	uint64 ChainGuard : 1;
	uint64 DualGuard : 1;
	uint64 Sortie : 1;
	uint64 Dead : 1;
	uint64 EscapeHere : 1;
	uint64 DiedHere : 1;
	uint64 JoinHere : 1;
	uint64 PureHide : 1;
	uint64 DisposHide : 1;
	uint64 ViewOut : 1;
	uint64 UnderRoof : 1;
	uint64 LockedUpdate : 1;
	uint64 Removing : 1;
	uint64 Remagicing : 1;
	uint64 Rerewarping : 1;
	uint64 Guest : 1;
	uint64 DisposGuset : 1;
	uint64 Engaging : 1;
	uint64 EngageAttack : 1;
	uint64 EngageLinked : 1;
	uint64 EngageAttacked : 1;
	uint64 Vision : 1;
	uint64 ExistDead : 1;
	uint64 Continued : 1;
	uint64 Defect : 1;
	uint64 BowCannon : 1;
	uint64 MagicCannon : 1;
	uint64 FireCannon : 1;
	uint64 IgnoreWholeSkill : 1;
	uint64 IgnoreEquipSkill : 1;
	uint64 IgnoreEquipEnhance : 1;
	uint64 RelayLeave : 1;
	uint64 IgnoreImmortal : 1;
	uint64 IgnoreGodUnit : 1;
	uint64 IgonreMapEnhance : 1;
	uint64 BeforeSortied : 1;
	uint64 IgnoreSupportedSkill : 1;
	uint64 Summon : 1;
	uint64 Lockon : 1;
	uint64 Reacted : 1;
	uint64 HoldHp : 1;
	uint64 IgnoreMapHistory : 1;
	uint64 ChangeEngaged : 1;
	uint64 LockedSupport : 1;
} UnitStatus;

typedef struct {
    int Version;
    byte Hp;
    byte Str;
    byte Tech;
    byte Quick;
    byte Luck;
    byte Def;
    byte Magic;
    byte Mdef;
    byte Phys;
    byte Sight;
    byte Move;
} CapabilityBase;

typedef struct {
    int Version;
    ubyte Hp;
    ubyte Str;
    ubyte Tech;
    ubyte Quick;
    ubyte Luck;
    ubyte Def;
    ubyte Magic;
    ubyte Mdef;
    ubyte Phys;
    ubyte Sight;
    ubyte Move;
} CapabilityBaseUbyte;

typedef struct {
    int Version;
    int Count;
    struct {
        SkillData Data;
        int Unknown1;
        int Unknown2;
    } Skill[Count]<optimize=false>;
} SkillArray;

typedef struct {
    int Version;
    int Num; 
    int Values[Num];
} UnitEnhanceValues;

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

typedef struct {
    BlockInfo Info;
    int Count;
    struct {
        int Unknown;
        LString Gid;
        byte RelianceSQ;
        if (RelianceSQ == 1) 
        {
            int Version;
            LString PartnerPid;
        }
        short BondsCount;
        struct {
            LString Pid;
            int Version;
            byte Level;
            ushort Exp;
            struct {
                int Version;
                int Count;
                int SkillHash[Count];
            } InheritedSkills;
            byte NotifiedLevelCapTalkQ;
        } BondList[BondsCount]<optimize=false, read=ReadLString(Pid)>;
    } GodList[Count]<optimize=false, read=ReadLString(Gid)>;
} GodBondBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    int Count;
    struct {
        int Unknown;
        SkillData GodData;
        int InstanceId;
        byte DarknessQ;
        byte ReservedDeletingQ;
        byte EscapingQ;
        byte Dirty;
        byte UnitCount;
        struct {
            LString Pid;
            ushort SynchroCounts;
        } Unit[UnitCount]<optimize=false>;
        byte SynchroWeaponCount;
        struct {
            LString Iid;
            byte Capacity;
            byte Power;
            byte Hit;
            byte Critical;
            byte Avoid;
            byte Secure;
            byte Tech;
            byte Quick;
            byte Def;
            byte Mdef;
            LString Sid;
        } SynchroWeapon[SynchroWeaponCount]<optimize=false>;;
    } God[Count]<optimize=false>;
} GodUnitBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    int Count;
    struct {
        int Owner;
        SkillData RingData;
        byte StockCount;
    } Ring[Count]<optimize=false>;
} RingBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    ubyte Unknown1;
    ubyte Count;
    struct {
        BlockInfo Info;
        UnitStatus Status;
        SkillData PersonData;
        SkillData JobData;
        CapabilityBase BaseStat;
        CapabilityBaseUbyte GrowStat;
        CapabilityBase LevelStat;
        uint GrowSeed;
        uint DropSeed;
        ubyte Level;
        ubyte Exp;
        ubyte Hp;
        byte X;
        byte Z;
        byte DisposX;
        byte DisposZ;
        float Angle;
        struct {
            ubyte ValidQ;
            if (ValidQ > 0)
                SkillData Person;
        } DontAttackPerson;
        uint DontAttackForceMask;
        struct {
            int Version;
            byte ItemMax_HardCoded_;
            while (ReadInt()==5) {
                UnitItem Item;
            }
        } ItemList;
        struct {
            int Version;
            while (ReadUShort()==0xEFCD || ReadUShort()==0xCCDB) {
                struct {
                    SkillData AccessoryData1;
                    SkillData AccessoryData2;
                } Accessory;
            }
        } AccessoryList;
        int ExtraSight;
        SkillArray EquipSkills;
        SkillArray PrivateSkills;
        SkillArray EquipSkills;
        struct {
            byte LearnedQ;
            if (LearnedQ != 0)
                SkillData JobLearnSkillData;
        } JobLearnSkill;
        int WeaponAptitudOriginal<format=hex>;
        int WeaponAptitud<format=hex>;
        int SelectedWeaponMask<format=hex>;
        struct {
            int Version;
            UnitEnhanceValues HubValues;
            UnitEnhanceValues FoodValues;
            UnitEnhanceValues ItemValues;
        } UnitEnhanceFactors;
        struct {
            int Version;
            UnitEnhanceValues Values;
        } UnitEnhanceCalculator;
        byte InternalLevel;
        if (ReadInt() == 7)
            struct {
                int Version;
                int Flag;
                ubyte Band;
                ubyte Acitve;
                ubyte Priority;
                ubyte HealRateA;
                ubyte HealRateB;
                ubyte BattleRateType;
                ubyte ProhibitEngageAttack;
                ubyte ProhibitRod;
                ubyte ProhibitOverlap;
                ubyte RerewarpCount;
                ubyte RerewarpCountMax;
                ubyte RerewarpLastX;
                ubyte RerewarpLastZ;
                LString RerewarpEventFlag;
                struct {
                    int Version;
                    ubyte Type;
                    byte X;
                    byte Z;
                    byte W;
                    byte H;
                } MoveLimitRange;
                ubyte VersusType;
                ubyte BulletPattern;
            } UnitAI;
        UnitEdit EditInfo;
        ubyte EngageCount;
        ubyte EngageTurn;
        struct {
            ubyte Version;
            ubyte Count;
            struct {
                int Key;
                int Value;
            } Record[Count]<optimize=false>;
        } UnitRecord;
        ubyte HpStockCount;
        ubyte HpStockMax;
        ubyte GodStateCount;
        ubyte ExtraHpStockCount;
        ubyte ExtraHpStockMax;
        int GodUnitInstanceId;
        int GodLinkInstanceId;
        int RingInstanceId;
        uint FortuneSeed;
        struct {
            byte ExistsQ;
            if (ExistsQ != 0)
                SkillData PersonData;
        } FortuneTarget;
        int Ident;
        ubyte MapHistoryIndex;
        ubyte RelayPlayerIndex;
        short SP;
        int OwnerUnit;
        byte LockTargetX;
        byte LockTargetZ;
    } Unit[Count]<optimize=false>;
    ubyte EndMark;
} UnitBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    short MaxData;
    struct {
        int Version;
        UnitItem Item;
    } Data[MaxData]<optimize=false>;
} TransporterBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    int Count;
    struct {
        LString PidPair;
        int Version;
        ubyte Level;
        byte Exp<name="Exp?">;
        byte Score<name="Score?">;
    } RelianceData[Count]<optimize=false, read=ReadLString(PidPair)>;
} UnitRelianceBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    byte Version;
    LString UserName;
    Language Lang;
    SkillData TitleData;
    float PlayTime;
    SkillData BackgroundData;
    SkillData FramData;
    SkillData TextDecoData;
    SkillData TextColorData;
    SkillData CharStampData;
    SkillData CommentData[3]<optimize=false>;
    LString CommentString;
    ubyte BirthMonth;
    ubyte BirthDay;
    Difficulty GameDifficulty;
    GameMode Mode;
    Gender PlayerGender;
    SkillData FavoriteCharacterData;
    SkillData FavoriteMapData;
    uint RelayPlayingCount;
    SkillData VersusThemeOfEditMap;
    int VersusRate;
    uint VersusPlayingCount;
    uint64 OwnerId;
    byte PublicQ;
    uint _Unknown<name="2">;
    uint _Unknown2<name="0x32">;
    // Todo

} ProfileCardBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    float Time;
    float UnscaleTime<name="UnscaleTime?">;
} GameTimeBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    BlockInfo Info;
    int Count;
} GameRestartDataBlock<size=(ReadInt(startof(this)))>;

typedef struct {
    int Checksum<format=hex>;
} CRCValidationBlock;

string TagNameRead( int t ) {
    local string s = "";
    local int asciiCode;
    local char c;
    while (t > 0)
    {
        asciiCode = t & 0xff;
        c = (char)asciiCode;
        SPrintf( s, "%c%s", c, s);
        t = (t >> 8);
    }
    return s;
}

typedef struct {
    int Offset;
    local int pos = FTell();
    FSeek(Offset);
    int TagName<read=TagNameRead>;
    if (TagNameRead(TagName) == "USER")
        GameUserData User;
    else if (TagNameRead(TagName) == "GDBD")
        GodBondBlock GodBond;
    else if (TagNameRead(TagName) == "GOD ")
        GodUnitBlock God;
    else if (TagNameRead(TagName) == "RING")
        RingBlock Ring;
    else if (TagNameRead(TagName) == "UNIT")
        UnitBlock Unit;
    else if (TagNameRead(TagName) == "TRAN")
        TransporterBlock Transporter;
    else if (TagNameRead(TagName) == "UREL")
        UnitRelianceBlock Reliance;
    else if (TagNameRead(TagName) == "PROF")
        ProfileCardBlock Profile;
    else if (TagNameRead(TagName) == "TIME")
        GameTimeBlock GameTime;
    else if (TagNameRead(TagName) == "REST")
        GameRestartDataBlock Restart;
    else if (TagNameRead(TagName) == "CRVL")
        CRCValidationBlock CRC32Validation;
    else
    {
        BufferBlock Buffer_WIP;
    }
    FSeek(pos);
} Tag<read = TagNameRead(TagName)>;