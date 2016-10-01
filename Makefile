# -----------------------------------------------------------------------------
# CMake project wrapper Makefile ----------------------------------------------
# -----------------------------------------------------------------------------

SHELL := /bin/bash
RM    := rm -rf
MKDIR := mkdir -p
BUILD_DIR := build

release: BUILD_TYPE=Release
release: ./$(BUILD_DIR)/Makefile
	@ $(MAKE) -C $(BUILD_DIR) -j8

debug: BUILD_TYPE=Debug
debug: ./$(BUILD_DIR)/Makefile
	@ $(MAKE) -C $(BUILD_DIR) -j8

all: ./$(BUILD_DIR)/Makefile
	@ $(MAKE) -C $(BUILD_DIR) -j8

./$(BUILD_DIR)/Makefile:
	@  ($(MKDIR) $(BUILD_DIR) > /dev/null)
	@  (cd $(BUILD_DIR) > /dev/null 2>&1 && cmake -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) ..)

clean:
	@ $(MAKE) -C $(BUILD_DIR) clean

do_perf:
	@  (cd $(BUILD_DIR) > /dev/null && ctest -L perf --verbose)

do_test:
	@  (cd $(BUILD_DIR) > /dev/null && ctest -L unit --verbose)

do_pack:
	@ (cd $(BUILD_DIR) > /dev/null && cpack -G TGZ)

distclean:
	@  ($(MKDIR) $(BUILD_DIR) > /dev/null)
	@  (cd $(BUILD_DIR) > /dev/null 2>&1 && cmake .. > /dev/null 2>&1)
	@- $(MAKE) --silent -C $(BUILD_DIR) clean || true
	@- $(RM) ./$(BUILD_DIR)/Makefile
	@- $(RM) ./$(BUILD_DIR)/CMake*
	@- $(RM) ./$(BUILD_DIR)/cmake.*
	@- $(RM) ./$(BUILD_DIR)/*.cmake
	@- $(RM) ./$(BUILD_DIR)/*.txt

ifeq ($(findstring distclean,$(MAKECMDGOALS)),)
	$(MAKECMDGOALS): ./$(BUILD_DIR)/Makefile
	@ $(MAKE) -C $(BUILD_DIR) $(MAKECMDGOALS)
endif
