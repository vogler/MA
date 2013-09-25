# Check style:
# http://matt.might.net/articles/shell-scripts-for-passive-voice-weasel-words-duplicates/
proof:
	@echo "weasel words: "
	sh bin/weasel.sh *.tex
	@echo
	@echo "passive voice: "
	sh bin/passive.sh *.tex
	@echo
	@echo "duplicates: "
	perl bin/dups.pl *.tex

diff:
	latexdiff --flatten ~/Desktop/MA/thesis.tex thesis.tex > diff.tex
	pdflatex diff.tex
	mv diff.pdf tmp.pdf
	rm -f diff.*
	mv tmp.pdf diff.pdf

tag:
	$(eval tag := $(shell git describe --abbrev=0 --tags))
	@echo "latest tag: $(tag)"
	$(eval tag2 := $(shell echo $(tag) | awk -F. -v OFS=. 'NF==1{print ++$$NF}; NF>1{if(length($$NF+1)>length($$NF))$$(NF-1)++; $$NF=sprintf("%0*d", length($$NF), ($$NF+1)%(10^length($$NF))); print}'))
	@echo "new tag: $(tag2)"
	-mv thesis.pdf thesis_$(tag2).pdf
	-mv diff.pdf diff_$(tag2).pdf
	git tag $(tag2)
	cd ~/Desktop/MA; git pull

test:
	-mv foo bar
	echo bla
