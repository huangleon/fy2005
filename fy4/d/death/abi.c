// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������������������������������ת��Ϊ�˵Ŀ��ܣ�������˶���ţһ����
�ǿױ���������ţͷ������ǣ֮�������ߣ���ʱ��ͭ�������ֱ��ô�ʹ��ʱ��
���ѡ�������������һ��Ӹ�����
LONG
        );
        set("exits", ([
		"up" : __DIR__"xuechi",
		"down" : __DIR__"banggan",
        ]) );
	set("no_fight",1);

	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-170);
	setup();
        replace_program(ROOM);
}
 
