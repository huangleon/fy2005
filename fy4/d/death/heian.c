// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ڰ���");
        set("long", @LONG
������޹�������������ͽ�������������ʮ����߸�����û��һ�ֿ־�Ⱥ�
���������˴����ĸе������ˣ�����ͨ������ķ��˺��٣�һ�����������ȥ�ɺ�
�ѣ�����Ҳ����������Ը�����һ����ʡ�Ļ��ᡣ���±��ǵ�ɽ���ˡ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"youguo",
		"down" : __DIR__"daoshan",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-140);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
