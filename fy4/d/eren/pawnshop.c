inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���⵱��");
        set("long", @LONG
���⵱�̣�����˼�壬��Ȼ����ԯ����������ˡ���ԯ�����ڽ������˳ơ���
���񡰣��ļ������û�������ò��գ��ǵ�����⣬�ع⣬�˹⡱���ϰ��ݡ���
����֪Ϊ��ʲô�������ٲ��ȶģ�Ҳ����Ϊ�˷���ͬ�ðɣ��ڴ˿��˼ҵ��̡�
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"vroad3",
	]));
        set("objects", ([
		__DIR__"npc/sanguang": 1,
	]) );
	set("coor/x",70);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
