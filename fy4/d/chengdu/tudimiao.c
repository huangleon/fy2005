// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
������Դ��Զ�����Ƕ�����Ȩ���ĳ�ݡ�����������ȣ�������ġ���ʳ��ĸ����
������Ǽ������ء��������ͼ򵥣�������ʯͷΪ�ڣ�һ��Ϊ����������ش����ǣ�
��Χ��ס�Ķ��Ǹ��и�ҵ���Ͷ�������Ȼ��ª��Ҳ���ʢ��������ǳɶ�����
�Ķ��Ҳ��á�
LONG
        );
	set("exits",([
  		"east" : __DIR__"beidajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}