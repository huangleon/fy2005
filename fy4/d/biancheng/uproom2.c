inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ի");
        set("long", @LONG
���Ⱥ���������飬��իֻ����˼������ĵط�����¥�²�ͬ��������õ÷�
�����ӣ��ı�Ĩ�Ű�����ҵ�������֮����ɫ���Ҿ���һ�ѿ��κ�һ�����ӣ�����
��д���ֵļ���ֽ��������Ŀ��������̡���Ҳ��ʽ�����ķ��ţ�����ֽ�������ģ�
��װ���̺�����ģ�Ҳ�м�ֱ�Ͷ������ϵġ�
LONG
        );
        set("exits", ([ 
		"west": __DIR__"corridor3",
		"east" : __DIR__"uproom3",
	]));
        set("objects", ([
	]) );
	set("wanma_discussion",1);
        set("coor/x",-10);
        set("coor/y",130);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
