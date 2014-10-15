
EXEC_DOXYGEN=doxygen
EXEC_MKDIR=mkdir
EXEC_CP=cp
EXEC_RM=rm

DOXYGEN_CONFIG=./Doxyfile
TARGET_DIR=../output/doxygen
TARGET_HTML_DIR=$(TARGET_DIR)/html

DOXYGEN_ASSETS_IMAGES_DIR=./assets/images
DOXYGEN_ASSETS_JS_DIR=./assets/javascripts
DOXYGEN_ASSETS_CSS_DIR=./assets/stylesheets

PROJECT_DIR=..
COMPONENTS_DIR=$(PROJECT_DIR)/components

SRC_DIR=$(PROJECT_DIR)

SRC_DIR_NAME=source
SRCS_DIRS := $(shell find $(PROJECT_DIR) -maxdepth 4 -type d -name $(SRC_DIR_NAME))
SRCS_DIRS += ../app
SRCS_FILES_DIRS := $(shell find $(SRCS_DIRS) -maxdepth 2 -type d)
SRCS := $(foreach dir,$(SRCS_FILES_DIRS),$(wildcard $(dir)/*.*))


SRC_ASSETS_DIR_NAME=assets
SRC_ASSETS_DIRS := $(shell find $(COMPONENTS_DIR) -maxdepth 3 -type d -name $(SRC_ASSETS_DIR_NAME)  )
SRC_ASSETS_DIRS += ../assets
SRC_ASSETS_FILES_DIRS := $(shell find $(SRC_ASSETS_DIRS) -maxdepth 2 -type d)
SRC_ASSETS := $(foreach dir,$(SRC_ASSETS_FILES_DIRS),$(wildcard $(dir)/*.*))


TARGET_HTML_INDEX := $(TARGET_HTML_DIR)/index.html


all: $(TARGET_HTML_DIR) $(TARGET_HTML_INDEX)

$(TARGET_HTML_DIR):
	@echo
	$(EXEC_MKDIR) -p $@

$(TARGET_HTML_INDEX): $(DOXYGEN_CONFIG) $(SRCS) $(SRC_ASSETS)
	@echo
	$(EXEC_DOXYGEN) $(DOXYGEN_CONFIG)
	$(EXEC_CP) -r $(DOXYGEN_ASSETS_IMAGES_DIR)/*  $(TARGET_HTML_DIR)/
	$(EXEC_CP) -r $(DOXYGEN_ASSETS_JS_DIR)/*  $(TARGET_HTML_DIR)/
	$(EXEC_CP) -r $(DOXYGEN_ASSETS_CSS_DIR)/*  $(TARGET_HTML_DIR)/
	$(EXEC_CP) -r $(SRC_ASSETS_DIRS)  $(TARGET_HTML_DIR)/

clean:
	$(EXEC_RM) -rf $(TARGET_HTML_DIR)/

show:
	echo SRCS_FILES_DIRS = $(SRCS_FILES_DIRS)
	@echo SRCS = $(SRCS)
	@echo ..........................................
	@echo SRC_ASSETS_DIRS = $(SRC_ASSETS_DIRS)
	@echo SRC_ASSETS = $(SRC_ASSETS)
	@echo ..........................................
	@echo TARGET_HTML_DIR = $(TARGET_HTML_DIR)
