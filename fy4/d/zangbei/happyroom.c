inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "�����С��");
        set("long", @LONG
��ɫ�ĵ�Ƕ�ڱ��ϣ���͵ĵƹ��������Ͼ��µĴ�������������̴ľ�����Ŵ�
��ʯ�����ӡ������û��Ǯ�򲻵��Ķ�����Ҳ��û�в���Ǯ�Ϳ��Եõ��Ķ�������
�������͵�׼����Ǯ��û���������⡣��Ϊ��������˾��Ǹ߼�Ƽ���ϴ󡣽�����
ʮ���ࡢƶ�������������������ˣ����Ͼ�û���κ��±�Ǯ����Ҫ��
LONG
        );
        set("exits", ([ 
		"west": __DIR__"bridge",
	]));
        set("objects", ([
        	__DIR__"npc/gao":	1,
        	
	]) );
        set("coor/x",-1660);
        set("coor/y",610);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	create_door("west","door","����","east",DOOR_CLOSED);
}
