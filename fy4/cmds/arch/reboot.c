// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object npc;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");

	seteuid(getuid());

	npc = new(NPC_DEMOGORGON);
	npc->move(START_ROOM);
	npc->start_shutdown();

	write("Ok��\n");

	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	reboot[0m
[0;1;37m����������������������������������������������������������������[0m   

��������Ϸ, ϵͳ�Ὺʼ������ʱ, ʮ������������𶯡�

[0;1;37m����������������������������������������������������������������[0m    
HELP
);
        return 1;
}
 
