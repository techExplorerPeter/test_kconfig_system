APP ?= app/test1
OUTPUT_PATH := output

INCLUDE_PATH := -I$(APP) -Idriver/test -Idriver/test1 -Idriver/test2 -I$(OUTPUT_PATH)

# define user .config setting
USER_CONFIG_SET := 
USER_CONFIG_SET += $(APP)/prj.conf

# define menuconfig .config path
DOTCONFIG_PATH := $(OUTPUT_PATH)/.config

# define user merged path
USER_RECORD_CONFIG_PATH := $(OUTPUT_PATH)/user_record.conf

# define autoconfig.h path
AUTOCONFIG_H := $(OUTPUT_PATH)/autoconfig.h

#define Kconfig path
KCONFIG_ROOT_PATH := Kconfig

include ./output/.config

VPATH := dirver

include driver/Makefile
#For windows work.
FIXPATH = $(subst /,\,$1)

BSW_STATIC := driver

OBJS_DIR := ./output

# enum the bsw obj and sources
ifneq ($(strip $(obj-y) $(obj-m) $(obj-)),)
dirs :=$(filter-out %.o,$(obj-y))
dirs_out := $(addprefix $(BSW_STATIC)/,$(dirs))
bsw_src := $(foreach dir,$(dirs_out),$(wildcard $(dir)/*.c))

# bsw_src += $(foreach dir,$(addprefix $(BSW_STATIC)/,$(filter-out %.o,$(obj-y))),$(wildcard $(dir)/*.c))
striped_bsw_obj += $(patsubst %.c,%.o,$(bsw_src))   
striped_bsw_obj += $(filter %.o,$(obj-y))
bsw_obj 		 += $(addprefix $(OBJS_DIR)/,$(notdir $(striped_bsw_obj)))
endif


all: $(APP)/main.o $(striped_bsw_obj) 
	@echo 11--------------------$(bsw_src)
	@echo 22--------------------$(striped_bsw_obj)
	@echo 33--------------------$(bsw_obj)
	gcc $^ -o $(OUTPUT_PATH)/main.exe
$(APP)/main.o: $(APP)/main.c $(AUTOCONFIG_H)
	gcc $< $(INCLUDE_PATH) -c -o $@
driver/test/%.o: driver/test/%.c $(AUTOCONFIG_H)
	gcc $< $(INCLUDE_PATH) -c -o $@

driver/test1/%.o: driver/test1/%.c $(AUTOCONFIG_H)
	gcc $< $(INCLUDE_PATH) -c -o $@

driver/test2/%.o: driver/test2/%.c $(AUTOCONFIG_H)
	gcc $< $(INCLUDE_PATH) -c -o $@

clean:
	del /q /s $(call FIXPATH, $(APP)/main.o driver/driver_test.o $(OUTPUT_PATH))

$(AUTOCONFIG_H):$(DOTCONFIG_PATH)
	python ../scripts/kconfig.py $(KCONFIG_ROOT_PATH) $(DOTCONFIG_PATH) $(AUTOCONFIG_H) $(OUTPUT_PATH)/log.txt $(DOTCONFIG_PATH)

$(USER_RECORD_CONFIG_PATH): $(USER_CONFIG_SET)
	@echo Using user config.
#	create user_record.conf to record current setting.
#	@copy $(call FIXPATH, $^) $(call FIXPATH, $@)
#	create .config by user config setting.
	python ../scripts/kconfig.py --handwritten-input-configs $(KCONFIG_ROOT_PATH) $(DOTCONFIG_PATH) $(AUTOCONFIG_H) $(OUTPUT_PATH)/log.txt $(USER_CONFIG_SET)

export KCONFIG_CONFIG=$(DOTCONFIG_PATH)
$(DOTCONFIG_PATH):$(USER_RECORD_CONFIG_PATH)
	@echo .config updated

menuconfig:$(DOTCONFIG_PATH)
#	set KCONFIG_CONFIG=$(DOTCONFIG_PATH)
	menuconfig $(KCONFIG_ROOT_PATH)