// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��԰");
        set("long", @LONG
�����ǻ���Ӫ�ĺ�԰����Χ�����ҡ��桢�������Ѽ�ĵ������ҩϡ��
Ʒ�ֺ͸����滨�������԰�ڣ�����ʱ�ڣ���ˮ������������������ʢһʱ��
LONG
        );
	set("exits",([
  		"west" : __DIR__"houhuayuan1",
  		"east" : __DIR__"houhuayuan3",
  		"north" : __DIR__"caochang2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}