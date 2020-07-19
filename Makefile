exp: exp_framework.c
	gcc $^ -g -o $@

1: 1.c
	gcc $^ -g -m32 -fno-stack-protector -z execstack -O0 -o $@

2: 2.c
	gcc $^ -g -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack -O0 -o $@

3: 3.c
	gcc $^ -g -m32 -fno-stack-protector -O0 -o $@
4: 4.c
	gcc $^ -g -m32 -fno-stack-protector -O0 -o $@
5: 5.c
	gcc $^ -g -m32 -fno-stack-protector -O0 -o $@
