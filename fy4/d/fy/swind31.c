#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIC"���ƽ�"NOR);
    set("long", @LONG
�ֵ�����ˮϴ����ô�ĸɾ�������������·������羵��������߷��ߴ��ΰ��
˫�˺ϱ�������ʮ��һ�꣬������������ߡ����ֵĽֵ��ϳ��������µĻ������
˿˿֬�۵������������ǴӴ�ֶ����Ʈ�㻨�굴�������ģ���Ũ���֬����Ϣ��
�����������֬������ơ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind32",
	"north" : __DIR__"swind3",
	"east" : __DIR__"pxhdian",
	"west" : __DIR__"qcyzdian",
      ]));


    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

