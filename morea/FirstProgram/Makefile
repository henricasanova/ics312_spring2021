KEYNOTES = $(shell find . -name '*.key' | sed "s/.key/.pdf/")
PAGES = $(shell find . -name '*.pages' | sed "s/.pages/.pdf/")

#TARGETS = $(KEYNOTES) $(PAGES) IGNORE
TARGETS =  $(KEYNOTES) IGNORE

default: $(TARGETS)

IGNORE:
	@if [ -f "_ignore/Makefile" ]; then  \
	   cd _ignore; make ;\
	fi \

%.pdf: %.key
	keynotetopdf $<

%.pdf: %.pages
	pagestopdf $<

clean:
	/bin/rm -f $(TARGETS)
