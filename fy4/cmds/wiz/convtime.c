inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int time;
        if(!arg || sscanf(arg,"%d",time)!=1)
        	return notify_fail("USAGE:convtime time.\n");
        write(sprintf("─·╩ф╚ы╡─╬кг║%dгм╢╘╙ж╩▒╝ф╬кг║%s\n",time,ctime(time)));
        return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	convtime [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╜лmud_time╫к╗п╬к╒¤│г╡─╩▒╝ф╧╘╩╛бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
    );
    return 1;
}
