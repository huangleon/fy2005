// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("╓╕┴ю╕ё╩╜г║follow <─│╚╦>|noneбг\n");

	if( arg=="none")
		if( me->query_leader() ) {
			me->set_leader(0);
			write("Ok.\n");
			return 1;
		} else {
			write("─у╧╓╘┌▓в├╗╙╨╕·╦ц╚╬║╬╚╦бг\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("╒т└я├╗╙╨ " + arg + "бг\n");

	if( !ob->is_character() )
		return notify_fail("╩▓ўсг┐╕·╦ц...." + ob->name() + "бг\n");

	if( ob==me )
		return notify_fail("╕·╦ц╫╘╝║г┐\n");

	me->set_leader(ob);
	message_vision("$N╛Ў╢и┐к╩╝╕·╦ц$n╥╗╞Ё╨╨╢пбг\n", me, ob);

	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 		follow [<╔·╬я>|none][0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
╒т╕Ў╓╕┴ю╚├─у─▄╕·╦ц─│╚╦╗Є─│╔·╬ябг
╚ч╣√╩ф╚ы follow none ╘Є═г╓╣╕·╦цбг
 
HELP
);
        return 1;
}
