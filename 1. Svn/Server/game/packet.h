// Search for:
	HEADER_CG_STATE_CHECKER							= 206,

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	HEADER_CG_MOVE_COSTUME_ATTR						= 207,
#endif

// Search for:
typedef struct SPacketGCPanamaPack
{
	BYTE	bHeader;
	char	szPackName[256];
	BYTE	abIV[32];
} TPacketGCPanamaPack;

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
typedef struct SMoveCostumeAttr
{
	BYTE			header;
	TItemPos		slotMedium;
	TItemPos		slotBase;
	TItemPos		slotMaterial;
} TMoveCostumeAttr;
#endif