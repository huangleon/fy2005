// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���۵�����������ͨ������޵��ľΪ�����������������ۻ��ƣ������ȱ�
������ʫ���࣬������ܴ���������ڴ˵أ��ر�����עĿ���������ס����᱾��
�����������̨��������һ��δ�Ⱦ��������������̼���ʫ�����²������
�ܣ������㲻���������϶ݣ��Ӵ����ڷ�Ϊ�ϱ����ڡ����б��ǽ����޵
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"daxiong",
  "east" : __DIR__"jinna2",
]));
	set("objects", ([
                __DIR__"npc/laomonk" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
