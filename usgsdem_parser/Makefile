EXEC=usgstoraw.py
TEST=10.2.1.1043901

test:
	./usgstoraw.py -f$(TEST).dem -o$(TEST).raw -x 768 -y 768

install:
	mv $(EXEC) /usr/bin/usgstoraw
	chmod +x /usr/bin/usgstoraw

uninstall:
	rm /usr/bin/usgstoraw
