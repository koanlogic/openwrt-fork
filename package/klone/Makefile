include $(TOPDIR)/rules.mk

PKG_NAME:=klone
PKG_VERSION:=3.0.0
PKG_RELEASE:=

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)$(PKG_RELEASE).tar.gz
PKG_SOURCE_URL:=http://koanlogic.com/download/klone/
PKG_MD5SUM:=

# custom toolchain
TC=$(PKG_BUILD_DIR)/wrt.tc

include $(INCLUDE_DIR)/package.mk

define Build/Configure
endef

define Build/Compile
	rm -rf $(PKG_INSTALL_DIR)
	mkdir -p $(PKG_INSTALL_DIR)
	# copy across custom Makefile and static+dynamic web content
	$(CP) $(CURDIR)/Makefile.klone $(PKG_BUILD_DIR)/Makefile
	$(CP) $(CURDIR)/webapp $(PKG_BUILD_DIR)/
	$(CP) $(CURDIR)/mymisc $(PKG_BUILD_DIR)/
	# setup custom MaKL toolchain
	rm -f $(TC)
	for v in $(TARGET_CONFIGURE_OPTS); do echo $$$$v >> $(TC); done
	echo "CC=$(TARGET_CC) -I$(STAGING_DIR)/usr/include -L$(STAGING_DIR)/usr/lib" >> $(TC)
	echo "using toolchain: $(TC)"
	[ -f $(DL_DIR)/$(PKG_SOURCE) ] && $(CP) $(DL_DIR)/$(PKG_SOURCE) $(PKG_BUILD_DIR)
	$(MAKE) -C $(PKG_BUILD_DIR) 
endef

define Package/klone/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/kloned $(1)/usr/sbin/ 
endef

define Package/klone/description
	KLone demo application.
endef

define Package/klone
	SECTION:=net
	CATEGORY:=Network
	TITLE:=KLone demo application
	URL:=http://koanlogic.com/klone/
	DEPENDS:=+zlib +libopenssl
endef

$(eval $(call BuildPackage,klone))
