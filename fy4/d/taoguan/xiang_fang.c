#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬�᷿");
	set("long", @LONG
����ķ��䣬ȴ�ܸɾ�����������ǽ�Ϲ��ż���ɽˮ���������Ǽ��Ŵ�齣���
���ǽ�Ϲ��ż��ѳ���������һ��СС��ͭ¯�������������𣬼����������Ĵ�
�ĵ�ʿ���ڱ�Ŀ������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"da_yuan",
	]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/reg_taoist" : 2,
                __DIR__"npc/up_taoist" : 1,
                __DIR__"npc/m_taoist" : 1,
                __DIR__"npc/m_taoist" : 1,
                __DIR__"npc/huo" : 1,
	]));
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
