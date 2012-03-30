# Precondition: MaKL must be installed on build machine
include $(TOPDIR)/rules.mk

PKG_NAME:=libu
PKG_REV:=b75cdd6175cc844803057088a9cf65f375e41997
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE:=$(PKG_NAME)-$(PKG_REV).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)
PKG_SOURCE_URL:=git@github.com:koanlogic/libu.git
PKG_SOURCE_VERSION:=$(PKG_REV)

# custom toolchain
TC=$(PKG_BUILD_DIR)/wrt.tc

include $(INCLUDE_DIR)/package.mk

define Package/libu/description
	LibU is a multiplatform utility library written in C.
endef

define Package/libu
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=LibU Utility Library
	URL:=http://koanlogic.com/libu/
endef

# keep debug active for development
define Build/Configure
	cd $(PKG_BUILD_DIR) && \
	CC="$(TARGET_CC) -fPIC -I$(STAGING_DIR)/usr/include -L$(STAGING_DIR)/usr/lib" \
	makl-conf -v \
		$(PKG_CONFIGURE_OPTS) \
		--enable_shared \
		--extra-cflags=-DU_TOKEN_SZ=256 \
		--prefix="$(PKG_INSTALL_DIR)" \
		--no_docs \
		--enable_debug \
		--enable_warns \
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
		-C $(PKG_BUILD_DIR) \
		all install
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) -r $(PKG_INSTALL_DIR)/include/* $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/lib/libu.so* $(1)/usr/lib
endef

define Package/libu/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/lib/libu.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libu))
