inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ú�ׯ����");
        set("long", @LONG
�����кܿ���������������ľ���������оơ�����Ӵ����ս����������ڼ���
�������ϣ�һ����ʮ����Ĵ���������ʮ��ǰ�������������ׯ��Ѧ�������̶��
������Ѩ����ɨ������ɽ����������������Ǻ���ʮ��ǰһ����������ô�ս�����
���������ķ��Ź⡣----- ���������������أ�
LONG
        );
        set("exits", ([ 
		"east": __DIR__"xuevillage",
	]));
        set("objects", ([
		__DIR__"npc/xuebin": 1,
		__DIR__"npc/jiaren":	1,
	]) );
	set("coor/x",-2080);
        set("coor/y",580);
        set("coor/z",20);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
