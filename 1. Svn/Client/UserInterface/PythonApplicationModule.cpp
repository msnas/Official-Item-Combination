// Search for:
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	PyModule_AddIntConstant(poModule, "ENABLE_MOVE_COSTUME_ATTR", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_MOVE_COSTUME_ATTR", 0);
#endif