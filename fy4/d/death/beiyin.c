// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
�زص���ų�������Ȼ����̹ǣ�ԭ�����˱���ɽ������ɽ�˵ظ����ն�ĵ�
������ɽ��Ұ���ǹ»�Ұ���ζ఼͹��ɽ���վ����������룬����®�ң��㲻��
��Ӳ��ͷƤ��ǰ�ߡ�
LONG
        );
        set("exits", ([
		"northdown" : __DIR__"dizang",
		"southdown" : __DIR__"shandao",
        ]) );
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",10);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
