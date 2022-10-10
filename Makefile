all: test
.PHONY: all


.PHONY: test
test:
	@sh test.sh

.PHONY: clean
clean:
	@sh run_make.sh clean

.PHONY: fclean
fclean:
	@sh run_make.sh fclean

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all
