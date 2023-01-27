// Search for:
	ITEM_BELT,

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	ITEM_MEDIUM,			// Medium (Transfer)
#endif

// Search for:
enum EExtractSubTypes
{
	EXTRACT_DRAGON_SOUL,
	EXTRACT_DRAGON_HEART,
};

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
enum EItemMediumSubTypes
{
	MEDIUM_MOVE_COSTUME_ACCE_ATTR,
	MEDIUM_MOVE_COSTUME_ATTR,
};
#endif