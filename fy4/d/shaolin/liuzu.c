// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���۵�ͨ�������Ľݾ�����ľΪ�����������������ۻ��ƣ�����ԣ�����
֮�ϵ����֣������ȱ�֮�Ͼ���������ʫ������ɮ�˶��а�����д�ڴ˼��ߡ���
��ǽ��һ���ر�����עĿ���ഫΪ�������顰��������������������̨��ʱʱ�ڷ�
�ã�Īǲ�г�������
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"daxiong",
  "west" : __DIR__"liuzu2",
]));
	
	   set("objects", ([
       	__DIR__"npc/monk20b1" : 1,
       	__DIR__"npc/monk20c1" : 1,
       ]) );
	
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
