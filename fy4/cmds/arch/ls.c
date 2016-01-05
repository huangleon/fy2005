// ls.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int mark_loaded;
	int i, j, w, col;
	string dir;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{if (file_size(dir) == -2) return notify_fail("─┐┬╝╩╟┐╒╡─бг\n");
		else
		return notify_fail("├╗╙╨╒т╕Ў─┐┬╝бг\n");
	}

	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] += "/";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
	}
	write("─┐┬╝г║" + dir + "\n");
	col = 70 / (w+6);
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
			printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
				file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
				((i+1)%col)?"  ":"\n");
	else write("    ├╗╙╨╚╬║╬╡╡░╕бг\n");
	write("\n");
	
	return 1;	
}

int help(object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	ls [<┬╖╛╢├√>][0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┴╨│Ў─┐┬╝╧┬╦∙╙╨╡─╫╙─┐┬╝╝░╡╡░╕, ╚ч╣√├╗╙╨╓╕╢и─┐┬╝, ╘Є┴╨│Ў╦∙╘┌─┐┬╝
╡──┌╚▌гм╦∙┴╨│Ў╡─╡╡░╕╓╨╟░├ц▒ъ╩╛ * ║┼╡─╩╟╥╤╛н╘╪╚ы╡─╬я╝■бг
 
└¤:
'ls /' ╗с┴╨│Ў╦∙╙╨╬╗ь╢╕∙─┐┬╝╧┬╡─╡╡░╕╝░╫╙─┐┬╝.

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
 
HELP
	);
	return 1;
}
