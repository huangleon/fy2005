// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;
    
#ifdef	ENCRYPTED_WRITE	
		return notify_fail("╕├├№┴ю╓╗╙╨╘┌гфгхгЎ╒╛╡у▓┼╨ш╥к╘╦╨╨бг\n");
#endif      
       
    if(!me->query("env/yesiknow")) return notify_fail("╒т╕Ў╓╕┴ю╥╤╛н▒╗╖╧│¤┴╦гб\n");
		
	cmds = me->query_commands();
	write("─у╔э╔╧╝░╦─╓▄╡─╬я╞╖╙ы╦∙╘┌╡─╗╖╛│╠с╣й╥╘╧┬╓╕┴юг║\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}

int help()
{
	write(@TEXT
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	localcmds[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┴╨│Ў─у╔э╔╧╝░╦─╓▄╡─╬я╞╖╙ы╦∙╘┌╡─╗╖╛│╠с╣й╡─╦∙╙╨╓╕┴юбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
TEXT
	);
	return 1;
}

