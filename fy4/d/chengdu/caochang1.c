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
  		"west" : __DIR__"yingfang1",
  		"east" : __DIR__"yingfang2",
  		"north" : __DIR__"chaotinghuoqiyingdamen",
  		"south" : __DIR__"caochang2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}