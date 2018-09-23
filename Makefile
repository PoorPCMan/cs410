.PHONY: clean All

All:
	@echo "----------Building project:[ hw2 - Debug ]----------"
	@cd "hw2" && "$(MAKE)" -f  "hw2.mk"
clean:
	@echo "----------Cleaning project:[ hw2 - Debug ]----------"
	@cd "hw2" && "$(MAKE)" -f  "hw2.mk" clean
