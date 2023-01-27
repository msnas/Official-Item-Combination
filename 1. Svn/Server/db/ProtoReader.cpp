// Search for (on string arType[] =):
		"ITEM_BELT",

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		"ITEM_MEDIUM",
#endif

// Search for:
	static string arSub31[] = { "EXTRACT_DRAGON_SOUL", "EXTRACT_DRAGON_HEART" };

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	static string arSub36[] = { 
		"MEDIUM_MOVE_COSTUME_ACCE_ATTR",
		"MEDIUM_MOVE_COSTUME_ATTR"
	};
#endif

// Search for:
		arSub31,
		0,
		0,
		0,

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		arSub36,
#endif

// Search for:
		sizeof(arSub31)/sizeof(arSub31[0]),
		0,
		0,
		0,

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		sizeof(arSub36) / sizeof(arSub36[0]),
#endif