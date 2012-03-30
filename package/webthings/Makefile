# Precondition: MaKL must be installed on build machine
include $(TOPDIR)/rules.mk

PKG_NAME:=webthings
PKG_REV:=c0398bd5ce397c13ccff1f1b6e0513bad9998f90
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE:=$(PKG_NAME)-$(PKG_REV).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)
PKG_SOURCE_URL:=git@github.com:koanlogic/webthings.git
PKG_SOURCE_VERSION:=$(PKG_REV)

# custom toolchain
TC=$(PKG_BUILD_DIR)/wrt.tc

include $(INCLUDE_DIR)/package.mk

define Package/webthings/description
	Webthings simplifies bridging between the Web and IoT.
endef

define Package/webthings
	SECTION:=net
	CATEGORY:=Network
	TITLE:=Webthings Web/IoT bridge
	URL:=http://github.com/koanlogic/webthings
	DEPENDS:=+klone +libu +libevent2 +librt
endef

# keep debug active for development
define Build/Configure
	cd $(PKG_BUILD_DIR)/bridge/sw && \
	CC="$(TARGET_CC) -fPIC -I$(STAGING_DIR)/usr/include -L$(STAGING_DIR)/usr/lib" \
	makl-conf -v \
		$(PKG_CONFIGURE_OPTS) \
		--prefix="$(PKG_INSTALL_DIR)" \
		--enable_shared \
		--libs="$(STAGING_DIR)" \
		--dir-lib="$(STAGING_DIR)"/usr/lib \
		--dir-inc="$(STAGING_DIR)"/usr/include \
		--enable_debug \
		--enable_warns \
		--enable_extra \
		--cross_compile
endef

define Build/Compile
	rm -rf $(PKG_INSTALL_DIR)
	mkdir -p $(PKG_INSTALL_DIR)
	# setup custom MaKL toolchain
	rm -f $(TC)
	for v in $(TARGET_CONFIGURE_OPTS); do echo $$$$v >> $(TC); done
	echo "CC=$(TARGET_CC) -fPIC -I$(STAGING_DIR)/usr/include -L$(STAGING_DIR)/usr/lib" >> $(TC)
	echo "using toolchain: $(TC)"
	makl \
		--makl-tc-file=$(PKG_BUILD_DIR)/wrt.tc \
		--makl-tc-onthefly \
		-C $(PKG_BUILD_DIR)/bridge/sw \
		all install
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/lib/libevcoap.so* $(1)/usr/lib
endef

define Package/webthings/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/bin/kink $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,webthings))
