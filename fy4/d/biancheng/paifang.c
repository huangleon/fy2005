inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ڸ���");
        set("long", @LONG
�ڸ����Ǹ��ܸߵ�����Ʒ����������¿����������ǰ����ɵġ��Ʒ����ԣ�
��Щ�߸ߵ͵͵�С¥�����Ӷ��ǿ��ŵģ�ÿ�����ڶ���������ͷ����������������
���Ʒ�ǰվ�ŵĶ�ʮ�Ÿ��ˡ���ʮ�Ÿ��������¡�ͷ�����Ű�����ˡ���Щ����
����Ů���������٣�ÿ��������������ű�ѩ���Ĺ�ͷ�󵶡�ÿ�������ϣ�����
�����޷����ݵı�׳֮ɫ��������һȺ������ս����ȥ�͵���ƴ������ʿ��
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"road6",
	]));
        set("objects", ([
        	__DIR__"npc/guowei":	1,
        	__DIR__"npc/guobaobao":	1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",10);
        set("coor/z",0);
        set("no_lu_letter",1);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
