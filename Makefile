#
# Makefile
#
# Make file for pwlib library
#
# Portable Windows Library
#
# Copyright (c) 1993-1998 Equivalence Pty. Ltd.
#
# The contents of this file are subject to the Mozilla Public License
# Version 1.0 (the "License"); you may not use this file except in
# compliance with the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
# the License for the specific language governing rights and limitations
# under the License.
#
# The Original Code is Portable Windows Library.
#
# The Initial Developer of the Original Code is Equivalence Pty. Ltd.
#
# Contributor(s): ______________________________________.
#
# $Revision$
# $Author$
# $Date$
#

ifeq (,$(wildcard make/ptbuildopts.mak))
  dummy := $(info Running configure)$(shell ./configure)
  ifeq (,$(wildcard make/ptbuildopts.mak))
    dummy := $(error Configure failed, check config.log for reasons)
  endif
endif

include make/ptbuildopts.mak

  
ifeq ($(DEBUG),)
default :: optshared
else
default :: debugshared
endif

all :: 

include make/ptlib.mak

SUBDIRS := src
ifeq (1, $(HAS_PLUGINS))
SUBDIRS += plugins
endif

ifeq (1, $(HAS_SAMPLES))
SUBDIRS += samples/hello_world \
           samples/dnstest \
           samples/httptest \
           samples/ipv6test \
           samples/find_ip \
           samples/map_dict \
           samples/netif \
           samples/sockbundle \
           samples/stunclient \
           samples/thread \
           samples/url \
           samples/vcard
endif

ifeq ($(OSTYPE),mingw)
ARCH_INCLUDE=msos
else
ARCH_INCLUDE=unix
endif

# override P_SHAREDLIB for specific targets
optshared   debugshared   bothshared   :: P_SHAREDLIB=1
optnoshared debugnoshared bothnoshared :: P_SHAREDLIB=0

# and adjust shared lib names
ifeq (,$(findstring $(OSTYPE),Darwin cygwin mingw))
  LIB_SONAME   = $(PTLIB_FILE).$(MAJOR_VERSION).$(MINOR_VERSION)$(BUILD_TYPE)$(BUILD_NUMBER)
  DEBUG_SONAME = $(PTLIB_DEBUG_FILE).$(MAJOR_VERSION).$(MINOR_VERSION)$(BUILD_TYPE)$(BUILD_NUMBER)
else
  LIB_SONAME   = $(subst .$(LIB_SUFFIX),.$(MAJOR_VERSION).$(MINOR_VERSION)$(BUILD_TYPE)$(BUILD_NUMBER).$(LIB_SUFFIX),$(PTLIB_FILE))
  DEBUG_SONAME = $(subst .$(LIB_SUFFIX),.$(MAJOR_VERSION).$(MINOR_VERSION)$(BUILD_TYPE)$(BUILD_NUMBER)._d$(LIB_SUFFIX),$(PTLIB_FILE))
endif

# all these targets are just passed to all subdirectories
$(subst tagbuild,,$(STANDARD_TARGETS)) ::
	@set -e; $(foreach dir,$(SUBDIRS),if test -e $(dir) ; then $(MAKE) -C $(dir) $@; fi; )

update:
	svn update
	$(MAKE) bothdepend both

ptlib:
	$(MAKE) -C src both

docs:
	rm -rf html
	doxygen ptlib_cfg.dxy > doxygen.out 2>&1

install:
	( for dir in $(DESTDIR)$(LIBDIR) \
		     $(DESTDIR)$(PREFIX)/bin \
		     $(DESTDIR)$(PREFIX)/include/ptlib \
                     $(DESTDIR)$(PREFIX)/include/ptlib/$(ARCH_INCLUDE)/ptlib \
                     $(DESTDIR)$(PREFIX)/include/ptclib \
                     $(DESTDIR)$(PREFIX)/share/ptlib/make ; \
		do mkdir -p $$dir ; chmod 755 $$dir ; \
	done )
	( for lib in  $(PT_LIBDIR)/$(LIB_SONAME) \
	              $(PT_LIBDIR)/$(DEBUG_SONAME) \
	              $(PT_LIBDIR)/lib$(PTLIB_BASE)_s.a \
	              $(PT_LIBDIR)/lib$(PTLIB_BASE)_d_s.a ; \
          do \
	  ( if test -e $$lib ; then \
		$(INSTALL) -m 444 $$lib $(DESTDIR)$(LIBDIR); \
	  fi ) \
	done )
	( if test -e $(PT_LIBDIR)/$(LIB_SONAME); then \
	    (cd $(DESTDIR)$(LIBDIR) ; \
		rm -f $(PTLIB_FILE) ; \
		ln -sf $(LIB_SONAME) $(PTLIB_FILE) \
	    ) \
	fi )
	( if test -e $(PT_LIBDIR)/$(DEBUG_SONAME); then \
	    (cd $(DESTDIR)$(LIBDIR) ; \
		rm -f $(PTLIB_DEBUG_FILE) ; \
		ln -sf $(DEBUG_SONAME) $(PTLIB_DEBUG_FILE) \
	    ) \
	fi )
ifeq (1, $(HAS_PLUGINS))
	if test -e $(PT_LIBDIR)/device/; then \
	cd $(PT_LIBDIR)/device/; \
	(  for dir in ./* ;\
		do mkdir -p $(DESTDIR)$(LIBDIR)/$(DEV_PLUGIN_DIR)/$$dir ; \
		chmod 755 $(DESTDIR)$(LIBDIR)/$(DEV_PLUGIN_DIR)/$$dir ; \
		(for fn in ./$$dir/*.so ; \
			do $(INSTALL) -m 444 $$fn $(DESTDIR)$(LIBDIR)/$(DEV_PLUGIN_DIR)/$$dir; \
		done ); \
	done ) ; \
	fi
endif
	$(INSTALL) -m 444 include/ptlib.h                $(DESTDIR)$(PREFIX)/include
	$(INSTALL) -m 444 include/ptbuildopts.h          $(DESTDIR)$(PREFIX)/include
	(for fn in include/ptlib/*.h include/ptlib/*.inl; \
		do $(INSTALL) -m 444 $$fn $(DESTDIR)$(PREFIX)/include/ptlib; \
	done)
	(for fn in include/ptlib/$(ARCH_INCLUDE)/ptlib/*.h include/ptlib/$(ARCH_INCLUDE)/ptlib/*.inl ; \
		do $(INSTALL) -m 444 $$fn $(DESTDIR)$(PREFIX)/include/ptlib/$(ARCH_INCLUDE)/ptlib ; \
	done)
	(for fn in include/ptclib/*.h ; \
		do $(INSTALL) -m 444 $$fn $(DESTDIR)$(PREFIX)/include/ptclib; \
	done)
	(for fn in make/*.mak ; \
		do $(INSTALL) -m 444 $$fn $(DESTDIR)$(PREFIX)/share/ptlib/make; \
	done)

	mkdir -p $(DESTDIR)$(LIBDIR)/pkgconfig
	chmod 755 $(DESTDIR)$(LIBDIR)/pkgconfig
	$(INSTALL) -m 644 ptlib.pc $(DESTDIR)$(LIBDIR)/pkgconfig/

uninstall:
	rm -rf $(DESTDIR)$(PREFIX)/include/ptlib \
	       $(DESTDIR)$(PREFIX)/include/ptclib \
	       $(DESTDIR)$(PREFIX)/include/ptlib.h \
	       $(DESTDIR)$(PREFIX)/include/ptbuildopts.h \
	       $(DESTDIR)$(PREFIX)/share/ptlib \
	       $(DESTDIR)$(LIBDIR)/$(DEV_PLUGIN_DIR) \
	       $(DESTDIR)$(LIBDIR)/pkgconfig/ptlib.pc
	rm -f $(DESTDIR)$(LIBDIR)/lib$(PTLIB_BASE)_s.a \
	      $(DESTDIR)$(LIBDIR)/$(PTLIB_FILE) \
	      $(DESTDIR)$(LIBDIR)/$(LIB_SONAME)

distclean: clean
	rm -rf config.log config.err autom4te.cache config.status a.out aclocal.m4
	rm -rf lib*

# End of Makefile.in