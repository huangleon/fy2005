// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ۺ����");
        set("long", @LONG
�����ǡ��޿����䣬����Ҳң����Ҳ�Т������������Ķ���š��������
Ѻ����ͽ�����ȸոյ������ˣ�ۺ������������Ѻ�ģ����෸��ʵ��̫�࣬������
�˹�Ѻ���������͵�����İ�������
LONG
        );
        set("exits", ([
		"up" : __DIR__"huokeng",
		"down" : __DIR__"bashe",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-40);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
