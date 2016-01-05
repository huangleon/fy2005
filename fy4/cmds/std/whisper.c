// whisper.c

#include <ansi.h>
#define NEW_PERIOD 32400
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;
	
	if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("��ֻ����ʹ�ã�say����\n");
	
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲ�᣿\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");

	write( GRN "����" + ob->name() + "�Ķ�������˵����" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "����Ķ�������˵����" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	whisper <ĳ��> <ѶϢ>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�

[0;1;37m����������������������������������������������������������������[0m   
TEXT
	);
	return 1;
}
