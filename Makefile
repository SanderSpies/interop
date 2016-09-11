
default: development

development:
	ocamlbuild -package flow_parser Interop.byte
	./Interop.byte declaration-test.js > declaration-test-output.txt
	cat declaration-test-output.txt

.PHONY: test default
