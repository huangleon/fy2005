// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ĥ����");
        set("long", @LONG
һ���������ǵ�Ѫ��ζ����ֻ��ĥ�̲�ͣ��ת���ţ���ĥ�ĳ෢���۵���ͷ��
������ʱ�����š������ǡ�Ƥ��������Ĩ�������������������������������ﻨ��
�����ˡ����˷�����֮�أ��˷�����������ĥ�̣�եΪ�⽴��Ȼ�����ɺ�������
���裬ƴ���������������κ�������̡����������׵����Ҳ������������
LONG
        );
        set("exits", ([
		"up" : __DIR__"bopi",
		"down" : __DIR__"zhuidao",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-70);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
