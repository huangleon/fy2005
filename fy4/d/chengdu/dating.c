// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ɶ�ҩ��");
        set("long", @LONG
�����Ϳ�����ڳɶ����־�Ӫ��ҩ�ꡣҩ������󣬴�󷽱��˲��ˣ�
���¶�֮�ˡ�����ҩ�������Ų�ҩζ�����¸��Ҳ����Щ֪����֪���Ĳ�
ҩ���Ͷ�ҩ��
LONG
        );
	set("exits",([
  		"east" : __DIR__"nandajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}