inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", HIG"������"NOR);
    set("long", @LONG
���������ĺ����ݻ���ԣ������·����������ͨͨ����ӣ����̾���������
�켯���������Ǵ�ٹ��ˣ����Ƿ������䣬ֻҪ����������Ǯ����������ͻ��ܵ�
������к������������˵ģ�����ģ�����ߵģ����յģ���ҩ�ġ�������������
ƨ�ɵ������������˽��ѧ�����ϴ�������������������������������ַǷ���
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud2",
	"west" : __DIR__"didoor",
	"south" : __DIR__"washroom",
	"north" : __DIR__"yulong1",
      ]));
    set("objects", ([
	__DIR__"npc/caifan2" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",80);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}
