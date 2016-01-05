// imprison.c
#include "/doc/help.h"
#include <ansi.h>

#define SYNTAX	"╓╕┴ю╕ё╩╜г║imprison <═ц╝╥id> because <╘н╥Є> for <╢р╔┘╨б╩▒>\n"
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	object room;
	string name,reason;
	int duration;
	
	if (!wizardp(me)) 
		return notify_fail("─у├╗╙╨╚и┴ж╩╣╙├╒т╕Ў╓╕┴юбг\n");
	if (!arg) return notify_fail(SYNTAX);
	if (sscanf(arg, "%s because %s for %d", name, reason, duration)!=3)
		return notify_fail(SYNTAX);
		
	ob = find_player(name);
	if (!ob) return notify_fail("╒╥▓╗╡╜╒т╕Ў═ц╝╥бг\n");
	
	message_vision(HIR"\n$N╩╓╥╗╗╙гм╥╗╒є╬в╖ч╜л$n┤╡╚ы╖ч╘╞╝р╙№гогого\n"NOR,me,ob);
	tell_object(ob,HIR"─у╬е╖┤╖ч╘╞╣ц╘Єгм▒╗┤ж╖г╚ы╙№" + duration + "╨б╩▒бг\n\n"NOR);
	
	seteuid(geteuid(this_player(1)) );
	if(!(room =find_object(AREA_WIZ"jail")))
	room = load_object(AREA_WIZ"jail");
	ob->move(room);
	ob->set("imprison/start",time());
	ob->set("imprison/duration",60*60*duration);
	ob -> save();
	
	log_file("static/imprison", sprintf("[%s] %s imprison %s(%s) because %s for %d ╨б╩▒.\n",
		ctime(time())[0..15], me->query("id"), ob->query("name"), ob->query("id"), reason, duration));	
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : imprison <═ц╝╥id> because <╘н╥Є> for <╢р╔┘╨б╩▒>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╜л─│╕Ў═ц╝╥╜√я└╘┌╖ч╘╞╡─╝р╙№└ягм╘┌╝р╙№└я╩▓├┤╥▓╫Ў▓╗┴╦гм
╥╗╓▒╡╜▒╗╠с│Ў╝р╙№╗Є╒▀┤¤┬·╩▒╝ф

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
   );
   return 1;
}
