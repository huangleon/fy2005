inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
����ĳ�����һ��ˢ���˵����ӡ������ϵ��ż�ֻѬ���ȣ���̨�ϰ����軨��
���Ϲ��ŵ��ߣ������ټ��Ĵ��ӡ��������������󣬻�������ļ�������һ��
�����Ĵ�ľ�����ϰں��������ͳף����������ռ�õĺɰ������������ʵĶ�����
ݫ�������ˮ��Ļ�����
LONG
        );
        set("exits", ([ 
	"north": __DIR__"cabin4",
	]));
        set("objects", ([
        	__DIR__"npc/taipo":	1,
	]) );
	set("coor/x",-60);
        set("coor/y",-45);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
