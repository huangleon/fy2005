#include <command.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Ժ��");
	set("long", @LONG
��ʯС·�����˻��ԣ�������Ϊֹ��һ��СС�����������ڴ˴������ϵ�ǽ��
�Ͽ�������Ժ�������֡����Թ���һ��ľ�ƣ���д  [1;37m���䵱���ӣ���������[0;32m
LONG
	);
	set("exits", ([ 
		"enter" : __DIR__"wudang3",
  		"west" : __DIR__"wuroad3",
	]));
	set("outdoors", "wudang");
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
	
	
int valid_leave(object me, string dir)
{
        int i;
        object *inv, ro;

        if( dir != "enter" ) return 1;
		if (!userp(me))	return 1;
		
        if (me->query("family/family_name")=="�䵱��" || me->name()=="����" )
        	return 1;
		
		if (REWARD_D->riddle_check(me,"��������"))
			return notify_fail("ʯ��������������������߲Ŷԡ�\n");
		
		message_vision(HIY "��Ȼ�����м���������У�������ѽ����ץ��ѽ����\n"NOR, me);
    	message_vision(HIR "�������ˡ���һ����$N���Ժ������صش���һ����\n"NOR, me);
    	me->unconcious();
    	message_vision(HIY "�����䵱��ʿ��$N���еĶ�������һ�飬��$N���ص�ˤ���˵��ϣ�Ȼ��ת���뿪�ˡ�\n"NOR, me);	
    	inv = all_inventory(me);
    	for(i=0; i<sizeof(inv); i++) {
    		if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
			destruct(inv[i]);
        }
        return notify_fail("");
}

