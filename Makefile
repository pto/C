all:
	$(MAKE) -C ch01
	$(MAKE) -C ch02
	$(MAKE) -C ch03
	$(MAKE) -C ch04

clean:
	$(MAKE) -C ch01 clean
	$(MAKE) -C ch02 clean
	$(MAKE) -C ch03 clean
	$(MAKE) -C ch04 clean

cleanall:
	$(MAKE) -C ch01 cleanall
	$(MAKE) -C ch02 cleanall
	$(MAKE) -C ch03 cleanall
	$(MAKE) -C ch04 cleanall
