# Search for:
from _weakref import proxy

# Add after:
if app.ENABLE_MOVE_COSTUME_ATTR:
	import uiitemcombination

# Search for:
	def __DropItem(self, attachedType, attachedItemIndex, attachedItemSlotPos, attachedItemCount):
		if uiprivateshopbuilder.IsBuildingPrivateShop():			
			chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.DROP_ITEM_FAILURE_PRIVATE_SHOP)
			return

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			if uiitemcombination.IsCombinationOpen():
				return

# Search for:
		self.serverCommander=stringcommander.Analyzer()

# Add before:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			serverCommandList["ShowItemCombinationDialog"] = self.__ItemCombinationDialog

# Search for
	def __PlayMusic(self, flag, filename):
		flag = int(flag)
		if flag:
			snd.FadeOutAllMusic()
			musicinfo.SaveLastPlayFieldMusic()
			snd.FadeInMusic("BGM/" + filename)
		else:
			snd.FadeOutAllMusic()
			musicinfo.LoadLastPlayFieldMusic()
			snd.FadeInMusic("BGM/" + musicinfo.fieldMusic)

# Add after:
	if app.ENABLE_MOVE_COSTUME_ATTR:
		def __ItemCombinationDialog(self):
			self.interface.ItemCombinationDialogOpen()
	else:
		def __ItemCombinationDialog(self):
			return
