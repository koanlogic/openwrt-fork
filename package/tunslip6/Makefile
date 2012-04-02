include $(TOPDIR)/rules.mk

PKG_NAME:=tunslip6
PKG_REV:=25abb6197c7675eabca367601ec4aa67f935bfc8
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE:=$(PKG_NAME)-$(PKG_REV).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)
PKG_SOURCE_URL:=git@github.com:koanlogic/contiki-fork.git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/tunslip6/description
	Tunslip6 tool from Contiki.
endef

define Package/tunslip6
	SECTION:=net
	CATEGORY:=Network
	TITLE:=tunslip6
	URL:=http://www.contiki-os.org
endef

define Build/Compile
	CC="$(TARGET_CC)" \
	$(MAKE) -C $(PKG_BUILD_DIR)/tools tunslip6
endef

define Package/tunslip6/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_BUILD_DIR)/tools/tunslip6 $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,tunslip6))
