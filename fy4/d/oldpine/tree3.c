// Room: /d/oldpine/tree3.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������������������������ˣ�һ�������������˷�������ʹ������Ŀ���
������Ȼ��ľ�������������ֵط����¿���ʮ�ֲ��ǵģ������㻹���̲�ס����
һ�ۣ��������������Ҳ��ʮ�塢���ɸߣ�һ����ѣ����������ڵ���ȥ��ǰ�뿪
����ط���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tree2",
]));
        set("outdoors", "oldpine");

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",60);
	setup();
        
}