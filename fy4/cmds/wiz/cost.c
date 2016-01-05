// cost.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping before, after;
	int stime, usertime, eval_cost;

	if( me != this_player(1) ) me = this_player(1);

	seteuid(getuid());
   	if(!arg) 
   		return notify_fail("÷∏¡Ó∏Ò Ω£∫cost <÷∏¡Ó> [<≤Œ ˝> ....]\n");

    before = rusage();
	eval_cost = eval_cost();
	me->force_me(arg);
	eval_cost -= eval_cost();
	after = rusage();
	usertime = after["utime"] - before["utime"];
	stime = after["stime"] - before["stime"];
	printf("\nœµÕ≥ ±º‰£∫%d Œ¢√Î\n π”√’ﬂ ±º‰£∫%d Œ¢√Î\nEval cost£∫%d µ•Œª\n",
		stime, usertime, eval_cost );
		
	return 1;

}

int help()
{
	write( @TEXT
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36m÷∏¡Ó∏Ò Ω : 	cost <÷∏¡Ó> [<≤Œ ˝> .... ][0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

’‚∏ˆ÷∏¡Ó»√ƒ„≤‚¡ø¡Ì“ª∏ˆ÷∏¡Ó÷¥––À˘–Ëµƒ ±º‰°£

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   
TEXT
	);
	return 1 ;
}
