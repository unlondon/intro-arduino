SOURCES=$(wildcard *.md)
PDFS=$(SOURCES:.md=.pdf)

all: $(PDFS)

%.pdf: $(SOURCES)
	pandoc --slide-level 2 -t beamer -V theme:metropolis --template template.tex $(@:.pdf=.md) -o $@
	gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dPDFSETTINGS=/ebook -dNOPAUSE -dQUIET -dBATCH \
		-sOutputFile=$(@:.pdf=.ebook.pdf) $@

clean:
	rm -f *.pdf

live: $(PDFS)
	evince $(PDFS) &
	while /bin/true; do inotifywait $(SOURCES); make all; done

present: setup-projector $(PDFS)
	pdfpc $(PDFS)
	make disable-projector

setup-projector:
	xrandr --output VGA1 --above LVDS1 --auto

disable-projector:
	xrandr --output VGA1 --off

