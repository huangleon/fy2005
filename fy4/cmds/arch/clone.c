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
		return notify_fail("��Ҫ����ʲ�������\n");
	}
	
	file = resolve_path(me->query("cwd"), file);
	if(sscanf(file, "%*s.c") != 1) {
		file += ".c";
	}
	me->set("cwf", file);
	if(file_size(file) < 0) {
		return notify_fail("û���������(" + file + ")��\n");
	}
	if(!find_object(file)) {
		err = catch(call_other(file, "???"));
		if(err){
			write("����ʧ�ܣ�" + err + "\n");
			return 1;
		}
	}
	err = catch(obj = new(file));
	if(err){
		write("����ʧ�ܣ�" + err + "\n");
		return 1;
	}
	if(!objectp(obj)) {
		write("����ʧ�ܡ�\n");
		return 1;
	}
	/*log_file("CLONE_LOG", sprintf("(%s)\n%s cloned %s\n", ctime(time()), 
			me->query("name"), file));*/
	if(!stringp(msg = me->query("env/msg_clone"))) {
		msg = "$N�ڻ�������һ�����ó���$n��\n";
	}
	if(!obj->is_character() && obj->move(me)) {
		write(obj->query("name") + "���Ƴɹ������������Ʒ����\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	if(obj->move(environment(me))) {
		write(obj->query("name") + "���Ƴɹ�������������䡣\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	destruct(obj);
	return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
}

int help(object me) {
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	clone <����> [0m
[0;1;37m����������������������������������������������������������������[0m     

���ô�ָ��ɸ����κ����ƶ�֮���(������)��
���и�����Ʒ����LOG��¼��

[0;1;37m����������������������������������������������������������������[0m     
HELP
    );
    return 1;
}
