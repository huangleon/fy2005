// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ�����");
        set("long", @LONG
�����ѵ�ڤ������ģ�·��������ڤ����˾���ƹ������ֻأ���Ϊ�ң�Т���ڣ�
�壬���ƳͶ�����ѭ�������˱�Ӧ�����������޲�ǰ��һ�ã��Ծ�����
LONG
        );
        set("exits", ([
                "north" : __DIR__"naihe",
		"northwest" : __DIR__"zong",
		"southwest" : __DIR__"jie",
		"northeast" : __DIR__"xiao",
		"southeast" : __DIR__"yi",
        ]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("no_fight",1);
	set("no_magic",1);
	setup();
        replace_program(ROOM);
}
 
