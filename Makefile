
default: development

development:
	reasonbuild -package flow_parser Interop.byte
	./Interop.byte declaration-test.js > declaration-test-output.txt
	cat declaration-test-output.txt

.PHONY: test default
