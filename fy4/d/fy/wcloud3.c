inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"�����"NOR);
    set("long", @LONG
������ı������Թ�ı��ǽ�Ǯ����ܶ棬���濴����ȴҲ������κ�������
�������Խ�Ǯ���ܶ���һ���Ӵ�ĵ������������ģ���Ȼʳǣ������Ϲٽ���۾�
�˵أ������������ϱ���֮�ơ�����������լ�ķ�����һ���������������չ���
�������⣬�ƺ��ں������·����������һ�����ۣ����ǳ���������������ķ���
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"jindoor",
	"south" : __DIR__"yingou",
	"west"  : __DIR__"wcloud4",
	"east"  : __DIR__"wcloud2",
      ]));

    set("outdoors", "fengyun");
    set("coor/x",-160);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
