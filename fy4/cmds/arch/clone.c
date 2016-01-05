// clone.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/14/2001 by Daniel Q. Yu.
//

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file) {
	object obj;
	string err, msg;
	
	seteuid(geteuid(me));
	
	if(!file) {
		file = me->query("cwf");
	}
	if(!file) {
		return notify_fail("─у╥к╕┤╓╞╩▓ўс╬я╝■г┐\n");
	}
	
	file = resolve_path(me->query("cwd"), file);
	if(sscanf(file, "%*s.c") != 1) {
		file += ".c";
	}
	me->set("cwf", file);
	if(file_size(file) < 0) {
		return notify_fail("├╗╙╨╒т╕Ў╡╡░╕(" + file + ")бг\n");
	}
	if(!find_object(file)) {
		err = catch(call_other(file, "???"));
		if(err){
			write("╘╪╚ы╩з░▄г║" + err + "\n");
			return 1;
		}
	}
	err = catch(obj = new(file));
	if(err){
		write("╕┤╓╞╩з░▄г║" + err + "\n");
		return 1;
	}
	if(!objectp(obj)) {
		write("╕┤╓╞╩з░▄бг\n");
		return 1;
	}
	/*log_file("CLONE_LOG", sprintf("(%s)\n%s cloned %s\n", ctime(time()), 
			me->query("name"), file));*/
	if(!stringp(msg = me->query("env/msg_clone"))) {
		msg = "$N╘┌╗│╓╨├■╦ў╥╗╖мгм─├│Ў┴╦$nбг\n";
	}
	if(!obj->is_character() && obj->move(me)) {
		write(obj->query("name") + "╕┤╓╞│╔╣жгм╖┼╘┌─у╡─╬я╞╖└╕бг\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	if(obj->move(environment(me))) {
		write(obj->query("name") + "╕┤╓╞│╔╣жгм╖┼╘┌╒т╕Ў╖┐╝фбг\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	destruct(obj);
	return notify_fail("╬▐╖и╕┤╓╞▓╗─▄╥╞╢п╡─╬я╝■(" + file + ")бг\n");
}

int help(object me) {
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	clone <╡╡├√> [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m     

└√╙├┤╦╓╕┴ю┐╔╕┤╓╞╚╬║╬─▄╥╞╢п╓о╬я╝■(║м╣╓╬я)бг
╦∙╙╨╕┤╓╞╬я╞╖╢╝╙╨LOG╝═┬╝бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m     
HELP
    );
    return 1;
}
