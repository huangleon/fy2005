// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ɶ�����");
        set("long", @LONG
�˼䵱�̺�С����ȴ��һ��ܴ�Ĵ����ҡ����̵����ܶ����˶�������
��ǽ��Ҳ������ֻҪ���ܹ������Ķ�����ÿ�������϶���һ�ŵ�Ʊ�����ж�
���Ķ����������˻ҳ�����Ȼ�Ǻܶ��˽������䵱�ڴˣ�ȴ��Ҳû�л���ȡ��
LONG
        );
	set("exits",([
  		"north" : __DIR__"dongdajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}