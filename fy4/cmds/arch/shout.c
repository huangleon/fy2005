#include <ansi.h>
// shout.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) )
		return notify_fail("─┐╟░╘▌▓╗┐к╖┼═ц╝╥ shoutбг\n");
	if (!arg) return notify_fail("─у╧ы╥к┤є╜╨╩▓ўс?\n");
	shout( HIW+me->name() + "╫▌╔∙│д╨ег║" + arg + "\n"NOR);
	write(HIW"─у╫▌╔∙│д╨ег║" + arg + "\n"NOR);
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	shout <╤╢╧в>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
╒т╕Ў╓╕┴ю╚├─у╜л <╤╢╧в> ┤л╦═│Ў╚е, ╦∙╙╨╒¤╘┌╙╬╧╖╓╨╡─╚╦╢╝
╗с╠¤╝√─у╡─╗░.
 
see also : tune
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

HELP
    );
    return 1;
}
 
