// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
һ�������������������������˹�ȥ����֮�У����������������ش���
ÿ��һ�Σ���������ɽ�̿��Ȼ�󱻹��佽����ˮ��ָ�ԭ���������������Ͻ�
����㲻�ɵ��ĵ���٣�����������ǰδ������ʲô��ҵ���ɴ�������ۺ������
LONG
        );
        set("exits", ([
		"up" : __DIR__"yiuwang",
		"down" : __DIR__"yandu",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-30);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
