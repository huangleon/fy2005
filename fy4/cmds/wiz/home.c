// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;

//	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
//		return notify_fail("��û���Լ��Ĺ����ҡ�\n");

	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
//	me->move(user_path(geteuid(me)) + "workroom");
        me->move("d/wiz/jobroom"); 
        	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	home[0m
[0;1;37m����������������������������������������������������������������[0m   

���ô�һָ���ֱ�ӻص��Լ��Ĺ����ҡ�
������� 'msg_home' ����趨, ���ڳ����˶��ῴ���Ǹ�ѶϢ��

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
