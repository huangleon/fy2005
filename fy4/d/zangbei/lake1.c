inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ɽ����");
        set("long", @LONG
���ٸ���ɽ��������ղ�������µ����ᣬɢ����������ʯ�䣬�������񣬾�
Ө��͸����ˮ����̹ǣ�����ȴ���㻶�����󣬺��������Ϣ������ʯ�Բ�ʱ¶��
����С�ݡ�С�����ڸ�ԭ��������ҡҷ���������Ķ��ǵ�������
LONG
        );
        set("exits", ([ 
		"northwest":  __DIR__"haizi",
	]));
        set("objects", ([
        	__DIR__"npc/horse1":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2050);
        set("coor/y",550);
        set("coor/z",40);
	set("map","zbwest");
	setup();

}
