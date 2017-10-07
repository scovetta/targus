.PHONY: clean All

All:
	@echo "----------Building project:[ targus - Debug ]----------"
	@cd "targus" && "$(MAKE)" -f  "targus.mk" && "$(MAKE)" -f  "targus.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ targus - Debug ]----------"
	@cd "targus" && "$(MAKE)" -f  "targus.mk" clean
