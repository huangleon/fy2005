inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ŷ��������");
        set("long", @LONG
ŷ�������̵Ķ������紿��ϸ����֬����ζ�嵭�в����������������ʿ���
ˬ����ʳ���塣���������ɫ���˳ơ���������������Ư�����ϣ��ֳ�Ư������ζ
���ʣ�Ҳ�������������ڶ�����ʳ����֮���ͣ����иǹ�������¥�ļ��ơ�
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"vroad4",
	]));
        set("objects", ([
		__DIR__"npc/ouyang1":1,
		__DIR__"npc/ouyang2":1,
	]) );
	set("coor/x",80);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
