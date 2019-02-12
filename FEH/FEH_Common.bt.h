//--------------------------------------
//--- 010 Editor Binary Template
//
// File:
// Author:
// Revision:
// Purpose:
//--------------------------------------
const int offset = 0x20;

#ifndef KEYL
#define KEYL 34
#endif


typedef struct
{
    uint64 addr;
    local uint64 pos = FTell();
    if (addr !=0)
        FSeek(addr+offset);
        local int l = ReadStringLength(FTell());
        char content[l];
        FSeek(pos);
} CryptStr<read=ReadCryptedString>;

string ReadCryptedString(CryptStr &c)
{  
    if (c.addr == 0) return "Null";
    local int l1 = Strlen(c.content);
    local char xored[l1];
    local int i = 0;
	for (i=0; i<l1; i++)
    {
        if (c.content[i]!= XORKEY[i%KEYL])
            xored[i] = c.content[i] ^ XORKEY[i%KEYL];
        else
        {
            xored[i] = c.content[i];
        }
    }
    return xored;
}

// xored values (8bits to 64bits) ===================================================

typedef struct(int key)
{
	uint16 value<format=hex>;
	local int xorkey = key;
} XORED16<read=ReadXored16, write=WriteXored16>;

string ReadXored16(XORED16 &x)
{
    string s;
    SPrintf( s, "%d", (int)x.value^x.xorkey);
    return s;
}

void WriteXored16( XORED16 &x, string s )
{
    x.value = x.xorkey ^ Atoi(s);
}

typedef struct(byte key)
{
	byte value<format=hex>;
	local byte xorkey = key;
} XORED8<read=ReadXored8, write=WriteXored8>;

string ReadXored8(XORED8 &x)
{
    string s;
    SPrintf( s, "%d", (int)x.value^x.xorkey);
    return s;
}

void WriteXored8( XORED8 &x, string s )
{
    x.value = x.xorkey ^ Atoi(s);
}


typedef struct(int32 key)
{
	uint32 value<format=hex>;
	local int32 xorkey = key;
} XORED32<read=ReadXored32, write=WriteXored32>;

string ReadXored32(XORED32 &x)
{
    string s;
    SPrintf( s, "%d", (int)x.value^x.xorkey);
    return s;
}

void WriteXored32( XORED32 &x, string s )
{
    x.value = x.xorkey ^ Atoi(s);
}

typedef struct(int64 key) {
	int64 value<format=hex>;
	local int64 xorkey = key;
} XORED64<read=ReadXored64>;

string ReadXored64(XORED64 &x)
{
    string s;
    SPrintf( s, "%d", (int)x.value^x.xorkey);
    return s;
}

//================================================================================

typedef struct
{
    XORED16 hp(0xD632);
    XORED16 atk(0x14A0);
    XORED16 spd(0xA55E);
    XORED16 def(0x8566);
    XORED16 res(0xAEE5);
    FSkip(6);
} STATS;

typedef struct {
  XORED16 x(0xB332);
  XORED16 y(0x28B2);
} POSITION;
