inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
�������ߣ��ֵ������Ţ������¥����������ª��ľ�ݣ��ֵ����Ե��Ŵ�����
�Ĺ��ţ�ȴ���Ѳ��ưܻ���С��ͻȻ���˸���ߣ�ǰ��ķ���̫ƽ�ƺ�ֻ��һ�ּ�
���������������̵İ����������֬���Ρ�
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"road5",
	"northwest": __DIR__"temple",
	"north": __DIR__"paifang",	
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
