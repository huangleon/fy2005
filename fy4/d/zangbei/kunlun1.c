inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���ٺ�");
        set("long", @LONG
����ɳĮ���㵽������֮�ء����ٺӹ����ĺ�ˮ�������µĲ����·��Ź⡣��
�����Σ���ˮ˫�֣������һ֧����������ʲ�ӣ�ˮ�������Ƹ�������վ�������
�˱��ڵ��˻������ٺӵ��ϲ���[33m̫ƽ��[32m��ԭ��ֻ�Ǹ���վ��Ъ�ŵ��˶��ˣ�������
�����˼��ҵ��̡��ӱ���ͨ��[33m������[32m�����̺���������ɽ����û��
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"kunlun2",
		"southeast" : __DIR__"yangguan2",
		"southwest": AREA_TAIPING"mroad1",
		"north":	__DIR__"qingtongxia",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-500);
        set("coor/y",500);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
