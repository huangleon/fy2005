// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        return notify_fail("╓╕┴ю╕ё╩╜г║unchblk name \n");
    
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("╒т╕Ў╚╦▓╗╘┌гб\n");
	if (wizardp(ob)) return notify_fail("▓╗─▄┐к╞Ї╬╫╩ж╡─╞╡╡└бг\n");
	ob->delete("chblk_on");	
	tell_object(me, (string)ob->query("name")+"╡─╞╡╡└▒╗┐к╞Ї┴╦бг\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	unchblk <─│╚╦> [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┤╦├№┴ю╜л┐к╞Ї─│╚╦╡─╦∙╙╨╞╡╡└гм
░№└игугшгсгЇгмгЄгїгэгягЄгмгюгхгўгмгцг∙гм║═гЇгхгьгь

╧р╣╪╓╕┴ю chblk

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
    );
    return 1;
}

