// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�������Ժ");
        set("long", @LONG
�����Ҷ�Ϊ������������������Ũ����У���������ͨʯ�����������һ���ȣ�
���Ķ��������һ���������ص��������������������ĸ߷����ڣ������书������
ͨƪ�Ǿ����У��ıʺ�����ʹ�˰ٶ����ᡣ
LONG
        );
	set("exits",([
  		"north" : __DIR__"wuhouci3",
  		"south" : __DIR__"wuhouci1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}