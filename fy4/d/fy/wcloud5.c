
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIW"���Ŷ�"NOR);
    set("long", @LONG
�������ǿڣ��ֵ�Խ������������ȴ�������٣�·�߸��ٵ�ң�Ψ�м�������
�۵ĺ췿���ǳ����ؾ�����Ӫ���������ɳ���죬��ʱ��������ʻ����⣬����
���۵Ľ�����Ҳ��ɫ�Ҵң���Ͼ�˼����ԡ���ǰ�����ߴ������ǽ��ԶԶ������
ӳ�ű��������ɽ�ͣ����ͻ����۾ᡣ
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"barracks2",
	"west"  : __DIR__"wgate",
	"east"  : __DIR__"wcloud4",
      ]));

    set("outdoors", "fengyun");
    set("coor/x",-280);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
