inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"�����"NOR);
    set("long", @LONG
�����ǵ��񽭺���һ��������Ǯ���ܶ����ڣ��Ϲٽ����ľ�Ӫ���꣬ԭ����
���ưܵĵ����Ͻ�����ƬƬ��լ���뱱�����Ͻ��Ǿ�����������֮�ơ��ֵ�������
�ⱦ������ׯǮ¥�����������������쳣���ϲ����һ�ҡ��۲��ᡱϷ¥���Դ���
ǰ�뵽���������������ѳ�Ϊ���Ƴ���һ��ʤ����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"theater",
	"west"  : __DIR__"wcloud2",
	"east"  : __DIR__"fengdoor",
	"north":  __DIR__"adventure",
      ]));
    set("objects", ([
	__DIR__"npc/song": 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",-80);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);   //add by ldb 

}
