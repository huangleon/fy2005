inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�����ȵ�");
        set("long", @LONG
�������ԭ�����Ǹ�ɽ�ȣ������Ǹ����²������ɵ�ɽ�ȣ��ȵص��ס�����̦��
�ݡ��١�Ҷ����ð�����������ۼ��ڶ��ϣ��γ�����ͬ����һ�����������ס�˹�
�׵���ʵ�����������������ж��ԣ�Ѱ���ķ�������մ��һ��ͻ��Ե���ȥ������
�ľ���ԶԶ�ܿ���ʹ���������������ѵ���Ȼ�������塣��
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"diyugu",
	]));
        set("objects", ([
        	__DIR__"npc/xie":	1,
        	__DIR__"npc/tianmei":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1800);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}
