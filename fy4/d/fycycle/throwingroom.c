#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "���Ǵ���");
	set("long", HIC"

          ��     �� ��  ��  �� "NOR"

����һ��񷶥Բ�ݡ�����Ƕ�����ʯ��������ӳ���£��������ǵ����⡣
������һ�����磬�����ƺ�����һ�״ʡ�\n"

        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/throwingbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

