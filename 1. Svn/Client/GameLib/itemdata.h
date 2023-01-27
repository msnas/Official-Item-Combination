// Search for:
			ITEM_TYPE_BELT,

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
			ITEM_TYPE_MEDIUM,
#endif

// Search for:
		enum EMetinSubTypes
		{
			METIN_NORMAL,
			METIN_GOLD,
		};

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		enum EItemMediumSubTypes
		{
			MEDIUM_MOVE_COSTUME_ACCE_ATTR,
			MEDIUM_MOVE_COSTUME_ATTR,
		};
#endif