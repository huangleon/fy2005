inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"���ƽ�"NOR);
    set("long", @LONG
�ֵ����ߵ�������Զ����������˵��������������Ƴ�ʱ���̣��������ˣ���
�����������鵤��ҩ��������������������еĽ��Ҿ������͵ġ������ö����¿�
��һ����ũ�ӣ��ϰ��˵���Ǿ�����������ɽ���вɼ���ҩ��һ����ҽ�����㣬
�������������⣬������ũ����������ֶŮ����ѩ�����ճ�������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind4",
	"north" : __DIR__"swind32",
	"east" : __DIR__"shennong",
	"west" : __DIR__"pusheng",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
