#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬����");
	set("long", @LONG
һ�䲻��ĳ�����ȴ�Ǹɸɾ��������濿ǽ��һ���ܴ��¯�����ǽ�ǰ���
��̳�þơ��м��һ�Ŵ����ϰ��ŵķ��ˣ�ɢ��������������������ʿ����æ����
����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"da_yuan",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/o_taoist" : 2,
                __DIR__"npc/lin" : 1,
]));
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
