# Search for:
import localeInfo

# Add after:
if app.ENABLE_MOVE_COSTUME_ATTR:
	import uiitemcombination

# Search for:
		self.wndGuildBuilding = None

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			self.wndItemCombination = None

# Search for:
		wndChatLog = uiChat.ChatLogWindow()
		wndChatLog.BindInterface(self)

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			wndItemCombination = uiitemcombination.ItemCombinationWindow()
			wndItemCombination.BindInterface(self)
			self.wndItemCombination = wndItemCombination

# Search for:
		self.wndCube.SetItemToolTip(self.tooltipItem)
		self.wndCubeResult.SetItemToolTip(self.tooltipItem)

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR:
			self.wndItemCombination.SetInven(self.wndInventory)
			self.wndItemCombination.SetItemToolTip(self.tooltipItem)

# Search for:
		if self.dlgWhisperWithoutTarget:
			self.dlgWhisperWithoutTarget.Destroy()
			del self.dlgWhisperWithoutTarget

# Add after:
		if app.ENABLE_MOVE_COSTUME_ATTR and self.wndItemCombination:
			self.wndItemCombination.Destroy()

# Search for:
	def RefreshMall(self):
		self.wndMall.RefreshMall()

	def OpenItemMall(self):
		if not self.mallPageDlg:
			self.mallPageDlg = uiShop.MallPageDialog()

		self.mallPageDlg.Open()

# Add after:
	if app.ENABLE_MOVE_COSTUME_ATTR:
		def ItemCombinationDialogOpen(self):
			self.wndItemCombination.Open()
			if False == self.wndInventory.IsShow():
				self.wndInventory.Show()

			if self.wndInventory:
				self.wndInventory.SetItemCombination(self.wndItemCombination)