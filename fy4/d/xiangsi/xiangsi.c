// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��˼��");
        set("long", @LONG
���������·����������ǰ�����жϣ���ǰ�ľ�ɫ��Ȼ���ʣ�������ȥ
���������Ǳ̲�ǧ�꣬����������վ���±ߣ���ˬ��΢�ȵĺ��������������
�پ�������ˬ�����ǿ������ұ��Ǹ��ʵ�ɽ�ڣ���߲�Զ�ĵʹ��и�СС����
��������ȥ��Щ��ˮ��������Ϣ��
LONG
        );
	set("objects", ([
		__DIR__"npc/weeds" : 2,
		__DIR__"obj/vine" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"ninglu",
  		"west" : __DIR__"leidashi",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}
