# Search for:
	isOpenedBeltWindowWhenClosingInventory = 0	

# Add after:
	if app.ENABLE_MOVE_COSTUME_ATTR:
		itemCombination = None

# Search for:
	def __DropSrcItemToDestItemInInventory(self, srcItemVID, srcItemSlotPos, dstItemSlotPos):
		if srcItemSlotPos == dstItemSlotPos:
			return

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			if self.itemCombination:
				if self.itemCombination.IsShow():
					return

# Search for:
	def UseItemSlot(self, slotIndex):
		if constinfo.GET_ITEM_DROP_QUESTION_DIALOG_STATUS():
			return
		
		slotIndex = self.__InventoryLocalSlotPosToGlobalSlotPos(slotIndex)
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			if self.wndDragonSoulRefine.IsShow():
				self.wndDragonSoulRefine.AutoSetItem((player.INVENTORY, slotIndex), 1)
				return

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			if self.itemCombination:
				if self.itemCombination.IsShow():
					return

# Search for:
	def __SendMoveItemPacket(self, srcSlotPos, dstSlotPos, srcItemCount):
		if uiprivateshopbuilder.IsBuildingPrivateShop():
			chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.MOVE_ITEM_FAILURE_PRIVATE_SHOP)
			return

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			if self.itemCombination:
				if self.itemCombination.IsShow():
					return

# Search for:
	def OnMoveWindow(self, x, y):
		if self.wndBelt:
			self.wndBelt.AdjustPositionAndSize()

# Add after:
	if app.ENABLE_MOVE_COSTUME_ATTR:
		def SetItemCombination(self, itemCombination):
			self.itemCombination = itemCombination
