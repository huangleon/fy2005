// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������ɽ��ǧ�꺮���������ķ�����������������ڱ��ϣ�����صö��ǡ�
������ͷ����ü���ۣ���С���۳մ�����ʹ�����������ļ��̣��ñ��˵���ʧ
�����Լ��Ľ������������һ�����е��ڱ����ߣ��������̣�����֮����Ȼ��ͬ��
�䡣
LONG
        );
        set("exits", ([
		"up" : __DIR__"chebeng",
		"down" : __DIR__"tuoke",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-100);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
