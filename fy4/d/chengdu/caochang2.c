// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ٳ�");
        set("long", @LONG
���������н̾���һ����Ϊ��ʿ�����ĵط����м���̨���ơ�����̨���� 
LONG
        );
	set("exits",([
  		"west" : __DIR__"yingfang3",
  		"east" : __DIR__"yingfang4",
  		"north" : __DIR__"caochang1",
  		"south" : __DIR__"houhuayuan2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}