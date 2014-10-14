
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


SRC_DIR=../source 
SRC_DIRS := $(shell find $(SRC_DIR) -maxdepth 5 -type d)
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.*))

SRC_ASSETS_DIR=../assets
SRC_ASSETS_DIRS := $(shell find $(SRC_ASSETS_DIR) -maxdepth 5 -type d)
SRC_ASSETS := $(foreach dir,$(SRC_ASSETS_DIRS),$(wildcard $(dir)/*.*))


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
	$(EXEC_CP) -r $(SRC_ASSETS_DIR)  $(TARGET_HTML_DIR)/

clean:
	$(EXEC_RM) -rf $(TARGET_HTML_DIR)/

show:
	@echo SRCS = $(SRCS)
	@echo ..........................................
	@echo SRC_ASSETS = $(SRC_ASSETS)
	@echo ..........................................
	@echo TARGET_HTML_DIR = $(TARGET_HTML_DIR)
