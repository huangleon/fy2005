// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        return notify_fail("╓╕┴ю╕ё╩╜г║chblk name \n");
    
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("╒т╕Ў╚╦▓╗╘┌гб\n");
	if (wizardp(ob)) return notify_fail("▓╗─▄╣╪▒╒╬╫╩ж╡─╞╡╡└бг\n");
	ob->set("chblk_on",1);	
	tell_object(me, (string)ob->query("name")+"╡─╞╡╡└▒╗╣╪▒╒┴╦бг\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	chblk <─│╚╦> [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┤╦├№┴ю╜л╣╪▒╒─│╚╦╡─╦∙╙╨╞╡╡└гм
░№└игугшгсгЇгмгЄгїгэгягЄгмгюгхгўгмгцг∙гм║═гЇгхгьгь

╧р╣╪├№┴ю unchblk

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m    
HELP
    );
    return 1;
}
