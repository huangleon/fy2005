inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ԭ");
        set("long", @LONG
������ԭ�����������š���ɽ����������һƬ�����������ɫƽ���ߣ���ã�
����Ȼ��������˵صȴ������˸ߴ���ǰ������������ƴ��Ĳ�ԭ����û��·����
�������˳�����ˣ�̤��һ�����߿�ĳ�����ż���������۹�����Х������
LONG
        );
        set("long_night",@LONG
��ԭ��ҹ�Ǽ�į�ģ���Զ����ĸ߿գ������������ǵ㣬�����棬ҹ���˵ĵ�
��ҡҡ�ڰڣ������ӵ��еĹ�����裬�ڵ�·���ԣ�ȫ�Ǻڳ����ĺ�ɼ���֣���ǰ
�棬�ޱߵĲ�ԭ�ڷ���ɪɪ���죬�����Ƶ����������·����ë���Ȼ��
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"wild3",
		"west" : __DIR__"wild5",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1700);
        set("coor/y",710);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}

