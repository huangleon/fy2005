#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIC"���ƽ�"NOR);
    set("long", @LONG
�ֵ�����ˮϴ����ô�ĸɾ�������������·������羵��������߷��ߴ��ΰ��
˫�˺ϱ�������ʮ��һ�꣬������������ߡ����ߵĽֵ��ƺ�һ����խ�˺ܶ࣬��
Ϊ���������Ⱥ�Ķ���һЩ����ī�ͣ�������һ�������꣬�����滭����Զ������
�¿����õ�һ�һ�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind5",
	"north" : __DIR__"swind31",
	"east" : __DIR__"pictureshop",
	"west" : __DIR__"musicshop",
      ]));


    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

