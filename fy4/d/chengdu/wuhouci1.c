// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
���������ͳɼ��������ڱ���ǰ�ߵ�����ԭ�������Ϊ��ة�࣬��ǰ
������Ϊ�������������ֱ��񺺺�������׷��Ϊ�������������ʷ�����
������Ϊ�����������
LONG
        );
	set("exits",([
  		"north" : __DIR__"wuhouci2",
  		"south" : __DIR__"xidajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}