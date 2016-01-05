// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("─у╡─╬╫╩ж╡╚╝╢╠л╡═гм├╗╙╨╩╣╙├╒т╕Ў╓╕┴ю╡─╚и┴жбг\n");
	if( !arg || arg=="" )
		return notify_fail("╓╕┴ю╕ё╩╜г║wizlock <╬╫╩ж╡╚╝╢>\n");

	if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
	seteuid(getuid());
	if( LOGIN_D->set_wizlock(lvl) ) {
		write(sprintf("\n╜°╚ы╙╬╧╖╡╚╝╢╧▐╓╞╘┌%s\n",chinese_number(lvl)));
		return 1;
	} else
		return notify_fail("╔╧╧▀╚и╧▐╔ш╢и╩з░▄бг\n");
}

int help (object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	wizlock <╬╫╩ж╡╚╝╢>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╧▐╓╞─│╕Ў╡╚╝╢╥╘╧┬╡─╩╣╙├╒▀╜°╚ы╙╬╧╖бг
╞ф╓╨╬╫╩ж╡╚╝╢╖╓▒Ё╬к (immortal) (wizard) (arch) (admin), ╚Ї╥к╚б
╧√╧▐╓╞, ╘Є╩ф╚ы (player).

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m  
HELP
);
        return 1;
}
 
