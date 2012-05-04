include $(srctree)/arch/arm/mach-mv88de3100/mv88de3100.mk

ccflags-y += $(MV_DEFINE) $(HEADER_PATH)
#GALOIS_FIRMWARE_DIR = ../../GaloisSoftware

obj-$(CONFIG_MV88DE3100_GENERIC_DBG) += gdbg.o
gdbg-objs := generic_dbg.o
