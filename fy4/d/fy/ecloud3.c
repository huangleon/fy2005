inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIG"������"NOR);
    set("long", @LONG
����Ƕ��������ɵĵط�����Ϊ�����ǽ�ʨ�ھ֣���Ϊ��ʨ�ھ�����һ�л���
̫���Ļ�������׺�ȭ����ϱ��ľ�������ʨ�ơ����ͣ�����Ϊ��ʨ�ھ����߽�
����ʮ�꣬���СС����û�ж���һ֧�ڡ���������������Ĵ󲿷ֶ����������У�
���������Ľ������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud31",
	"west" : __DIR__"ecloud2",
	"north" : __DIR__"stopwin",
	"south" : __DIR__"goldlion",
      ]));
    set("objects", ([
	__DIR__"npc/wanfan" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",160);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
