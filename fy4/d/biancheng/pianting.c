inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ƫ��");
        set("long", @LONG
ƫ����Զ�����������������ƣ�ȴ���õø����ûʣ���ǽ�Ϲ������Ŵ��׵Ļ�
Ƥ�������Ⱥ�������Թض���ս��Ʒ��������д�һ����˻��������ĵط���ֻҪ
һ�����£���յ�̵Ĺ�����ܶ���һ�������ڵľƲˡ�ƫ����������ͨ��ͷ���
LONG
        );
        set("exits", ([ 
	"west": __DIR__"hall1",
	"east": __DIR__"corridor",
	]));
        set("objects", ([
		__DIR__"npc/murong1":	2,
	]) );
        set("coor/x",-5);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
