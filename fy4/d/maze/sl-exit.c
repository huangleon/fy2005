// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�������ǰ");
	set("long", @LONG
���������������죬�������ԣ�һ�н��޳���������Ҳ���پ���������ν�� 
����˥��Ϊ�����ѹ��塢ͷ�ϻ�ή��������ࡢҸ�º��������ֱ�������������� 
����һ������õ����ֻ�з𷨸�������ֵ��ӷ��л������������������δ��
����ŵ��з��������������御�
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"sl-maze/exit",
		"east" : __DIR__"sl-end",
	]));
        set("objects", ([
                             
        ]) );
        
        set("item_desc", ([
		"east": "һ��˶��������������У����������������ɮ��ϥ���ԡ���\n",
	]) );
	setup();
	
}

int	valid_leave(object who , string dir) {
	object room, guo;
	
	if (dir == "east") 
	{
		room = find_object(__DIR__"sl-end");
                if (room && room->usr_in())
			return notify_fail("�����ƺ����������������Ҿ�����䡣\n");
		if (REWARD_D->riddle_check(who,"��������")<2
				&& !REWARD_D->check_m_success(who,"��������"))
			return notify_fail("��Ϊ���з�����𣬾�Ȼ�������Ų���\n");
		if (room) {
			if (guo = present("afei",room))
				destruct(guo);
			room->reset();
		}
	}
	return ::valid_leave(who,dir);
}