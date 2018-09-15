.PHONY: clean All

All:
	@echo "----------Building project:[ hw1 - Debug ]----------"
	@cd "hw1" && "$(MAKE)" -f  "hw1.mk"
clean:
	@echo "----------Cleaning project:[ hw1 - Debug ]----------"
	@cd "hw1" && "$(MAKE)" -f  "hw1.mk" clean
