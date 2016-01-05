// describe.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;

	if( !arg ) return notify_fail("╓╕┴ю╕ё╩╜г║describe <├ш╩Ў>\n");
	if( arg=="none")
	{
		me->delete("long");
		write("├ш╩Ў╔╛│¤═ъ▒╧бг\n");
		return 1;
	}
	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("╟ы╜л─·╢╘╫╘╝║╡─├ш╩Ў┐╪╓╞╘┌░╦╨╨╥╘─┌бг\n");

	arg = implode(txt, "$NOR$\n") + "\n";

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("long", arg + NOR);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	describe <├ш╩Ў>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╚├─у╔ш╢и╡▒▒Ё╚╦╙├ look ╓╕┴ю┐┤─у╩▒гм╢╘─у╡─├ш╩Ўгм═и│г╡▒─у
╡─├ш╩Ў│м╣¤╥╗╨╨╩▒┐╔╥╘╙├ to describe ╡─╖╜╩╜└┤╩ф╚ыбг
╩ф╚ыdescribe none┐╔╥╘╔╛│¤─у╡─╡▒╟░├ш╩Ўбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
TEXT
	);
	return 1;
}
