#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"��Ǯ��"NOR);
    set("long", 
"����û���κα�Ķ�����ֻ��һ���ţ����Ľ���ͭ�ų����ţ���ǰȴû��һ
��������������ǽ�Ǯ����ܶ棬�������������������ڶ��ġ�����˫�����Ϲٽ��
һ�ִ��������µ�һ��������ȷҲ����Ҫ�κ���������Ϊ����û���˸��������
������ʹ�У�Ҳֻ�����ˡ���ǰ�߸�����һ����ң����飺"
+HIY"

                      ��    Ǯ    ��

"NOR        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud3",
  "north" : __DIR__"jinqian",
]));
        set("outdoors", "fengyun");
        set("objects", ([
                        ]) );

 set("coor/x",-160);
set("coor/y",40);
	set("coor/z",0);
set("map","fywest");
	setup();
//	replace_program(ROOM);
}

