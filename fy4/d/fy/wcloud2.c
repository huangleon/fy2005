inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", WHT"�����"NOR);
    set("long", @LONG
������Ǯ�ܶ棬��·����ĺ�լ�����۴��αȡ�ÿ���̺���ǰ����һ��Ƶ׽�
�ߵĽ�������������СС�ġ���Ǯ�����֣����б鲼���㣬���µ�һ��������
�����ҵ�Ǯׯǰ�಻���⡣�����ڷ��������Ĵ���ϣ�һ�з·��λ�һ�㡣����
����һ���ƽ�����ƺ��ͽ�����ߣ�ҫ�۵Ľ�ɫ����ѣĿ��Ϣ���������������С
���ӣ��������ӣ� 
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"qianyin",
	"north" : __DIR__"nanbank",
	"west"  : __DIR__"wcloud3",
	"east"  : __DIR__"wcloud1",
      ]));
    set("objects", ([
	__DIR__"npc/fat" : 1,
      ]) );


    set("outdoors", "fengyun");
    set("coor/x",-120);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
