inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ª�ﾡͷ");
        set("long", @LONG
С�ﾡͷ��һ��ľ��ǵ����ӣ��·��ѱ��紵��ҡ�����������������ſ�ǽ
������һ����Ĩ�Ͻ����ĺ�ֽ����ֽ��д�ţ����������⣬�ŷ�һ�䣬�����£���
���š���������ʮ���������ȸ����޵����޺�����
LONG
        );
    set("exits", ([ 
	"north" : __DIR__"smallroad3",
	"west" : __DIR__"cabin4",
	]));
    set("objects", ([
			"/obj/npc/inform_beggar":1,
      ]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",-40);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
