// friend.c 
// -silencer@fy4.com

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string msg, name, *friends,*new_friends;
	object body,ob;
	int i;
	
	if (me->query_temp("timer/big_cmd")+10 > time())
		return notify_fail("┤╦├№┴ю▒╚╜╧║─╖╤╧╡═│╫╩╘┤гм├┐╩о├ы╓╗─▄╓┤╨╨╥╗┤╬бг\n");
	else
		me->set_temp("timer/big_cmd",time());
			
	friends = me->query("friends_list");
	if (!friends) 
		friends=({});
	
	new_friends=friends;
	
	if( (int)me->query("sen") < 150 && !wizardp(me))
			return notify_fail("╓┴╔┘╨ш╥кг▒г╡г░╡у╨─╔ёбг\n");
	
	if( !arg ) {
		if (!sizeof(friends)) {
			write("─у╡─═и╤╢┬╝╩╟┐╒╡─бг\n");
			return 1;
		}	
		write(HIR"\n─у╡─║├╙╤┬╝├√╡е╚ч╧┬:"HIY"
===========================================================\n\n"NOR);			
		for (i=0;i<sizeof(friends);i++) {
			name=friends[i];
			ob = new(LOGIN_OB);
			ob->set("id", name);
			if (!ob->restore() || ob->query("id")=="hippo" || ob->query("id")=="gygao" || ob->query("id")=="silencer" ) {
				msg=sprintf(YEL"%-26s\t▓╗┤ц╘┌гм╥╤╫╘╢п┤╙─у╡─═и╤╢┬╝╓╨│¤├√бг\n"NOR, name);
				new_friends=new_friends-({name});
				write(msg);
				continue;
			}	
			if( objectp(body = find_player(name)) && geteuid(body)==name && ob->query("id")!="hippo" && ob->query("id")!="gygao" && ob->query("id")!="silencer" ) 
                		msg = sprintf(HIG"%-16s%-10s\t─┐╟░╒¤╘┌┴м╧▀╓╨бг\n"NOR, ob->query("name"),name); 
			else 
				msg=sprintf(CYN"%-16s%-10s\t─┐╟░▓╗╘┌┴м╧▀╓╨бг\n"NOR, ob->query("name"),name);
			write(msg); 
			destruct(ob);
		}
		write(HIY"
============================================================\n"NOR);
		me->set("friends_list",new_friends);
		if (!wizardp(me)) me->receive_damage("sen",150);
	}
	else	{
		ob = new(LOGIN_OB);
		ob->set("id", arg);
		if( !ob->restore() || ob->query("id")=="hippo" || ob->query("id")=="gygao" || ob->query("id")=="silencer" ) {
			write ("├╗╙╨╒т╕Ў═ц╝╥бг\n");
			return 1;
		}
		if ( !friends || member_array(arg,friends)==-1) { 
			if (sizeof(friends)>=15) {
				write(HIR"═и╤╢┬╝╓╨╫ю╢р╓╗─▄╙╨╩о╬х╕Ў├√╫╓гм╟ы╔╛╚е╥╗╨й▓╗│г╙├╡─бг\n"NOR);
				return 1;
			}
			me->set("friends_list",friends+({arg}));
			write(WHT"─у╜л═ц╝╥ "+ob->query("name")+"ги"+arg+"гй ╝╙╚ы═и╤╢┬╝бг\n"NOR);
		}else 	{
			me->set("friends_list",friends-({arg}));
			write(WHT"─у╜л═ц╝╥ "+ob->query("name")+"ги"+arg+"гй ┤╙═и╤╢┬╝╓╨╚е│¤┴╦бг\n"NOR);
		}
		destruct(ob);
	
	}

	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	friend [═ц╝╥╙в╙я┤·║┼][0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
  
┤╦╓╕┴ю╬к┐к╣╪╩╜гм╡┌╥╗┤╬┤Є╚ы╜л░╤╥╗╕Ў═ц╝╥├√╫╓╝╙╚ы─у╡─═и╤╢┬╝гм
╢╘═м╤∙╡─═ц╝╥├√╫╓╘┘┤╬▓┘╫ў╜л░╤┤╦├√╫╓┤╙═и╤╢┬╝╓╨╔╛│¤бг╚ч╣√▓╗
╕·╚╬║╬▓╬╩¤╘Є╜л╧╘╩╛═и╤╢┬╝╓╨╦∙╙╨═ц╝╥╡─╘┌╧▀╫┤┐Ўбг═и╤╢┬╝╓╨╫ю
╢р┐╔┤ц┤в╩о╬х╕Ў├√╫╓бг

see also : who, finger

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
 
