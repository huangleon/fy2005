// TIE@FY
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�زص�");
        set("long", @LONG
����ظ�֮�У���Ȼ��һ���ɹ���ʵ���������ţ�������ڤ�����ز���������
�����ഫ�ز�ԭΪ�������ӣ������õ��ھŻ������乫����˽�����������ֻأ���
�������������������Ա���α�������������Ѿ�֮�����������˴����ɵز�������
�ã������������ޱߴȺ������������
LONG
        );
        set("exits", ([
		"southup" : __DIR__"beiyin",
        ]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	set("no_fight",1);
	set("valid_startroom",1);
	setup();
        
}
 

void init()
{
	this_player()->set("startroom", base_name(this_object()));
}


