inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ���");
        set("long", @LONG
�߹����пڣ�������������࣬���ϴ�ɨ�øɸɾ�����û��һ�㸡����������
ͨ�Ĵ���·��ż��Ҳ�����¹ڻ��������ˣ���������ɫ��æ��С·���׵�������
���š��Ϲ�Ǯׯ������ţ����׺������������дһ���ܴ�ġ������֡�
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad2a",
	"east" : __DIR__"vroad4",
	"south" : __DIR__"bank",
	"north" : __DIR__"pawnshop",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",70);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
