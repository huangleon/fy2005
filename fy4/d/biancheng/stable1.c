inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
��ǰ��һ������ں����в�ͣ�ķ���������������ҶһƬƬ��������������
�ŵ���ǧ��ѡһ���������������ϼ������ס��С�ݣ����ɼ�����������һ��
������������ޣ�����ȣ��������м���С����
LONG
        );
        set("exits", ([ 
	"east": __DIR__"yard2",
	"north": __DIR__"stable2",
	]));
        set("objects", ([
        	__DIR__"npc/jiaolaoda":	1,
	]) );
	set("coor/x",-15);
        set("coor/y",95);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
