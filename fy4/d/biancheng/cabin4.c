inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "Сľ��");
        set("long", @LONG
������Ȼ��ª�����õ�ȴ��������ܸɾ������ϵı����Ǹջ��ġ��Ա߷���һ
ֻ�����裬�����̲裬������������ζ�أ�������ż��һ����������ǽ�ϵ������
�ӡ�һ���ţ��ͷ���Ա߰��ŷ�ү�衣
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"smallroad4",
	"south": __DIR__"cabin4a",
	]));
        set("objects", ([
	]) );
	set("coor/x",-60);
        set("coor/y",-40);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
