inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�����ô���");
        set("long", @LONG
ת�����磬����һ�����������˭��һ�ۿ����������������Ҫ��һ��������
��Ȼֻ������ʮ���ɿ���ֱ���������޷�����һ������Ҫ���ſ��ߵ���һ��ȥ��
˵����Ҫ����һ��ǧ����
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"hall3",
	"south": __DIR__"hall1",
	]));
        set("objects", ([
	]) );
        set("coor/x",-10);
        set("coor/y",110);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
