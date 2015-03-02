## ---------------------------------------------
## The top-level Makefile will build every samples

SAMPLES_DIR=samples
SAMPLES=$(addprefix $(SAMPLES_DIR)/,$(shell ls -1 $(SAMPLES_DIR)))
SAMPLES_BIN=$(addsuffix bin,$(SAMPLES)/)

all: clean $(SAMPLES_BIN)

$(SAMPLES_BIN):
	$(foreach sample,$(SAMPLES),\
		INPUT="$(INPUT)" make -C $(sample)\
		)

clean:
	$(foreach sample,$(SAMPLES),\
		make clean -C $(sample)\
		)
