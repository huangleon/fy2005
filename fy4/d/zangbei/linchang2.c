inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ֳ�");
        set("long", @LONG
�߳��������֣���ǰ����һ����ѩ�塢ɭ�֡��ݳ���Ϫ�����������ٲ��ͷ�ľ
�˵�ľ����ӳ��Ȥ��������һ���ŷ�����ľ�ϣ��ѵ���Сɽ��ߣ�Զ�������๱��
���ɹ���������ѩ�御���������ڹ�ȥ������������Ƕ�������������ʥ�ߵ�ϣ
�������룬���������Ĺ���֮�ء�
LONG
        );
        set("exits", ([ 
		"southup" : __DIR__"linchang1",
		"east":  __DIR__"woods2",
	]));
        set("objects", ([
        	__DIR__"obj/stump":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1640);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}
