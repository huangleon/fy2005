// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "ɽׯͥ԰");
  set("long",@LONG
ӭ��һ������ͥ԰������һ��СС�������أ������������̲������������
��������ǽ�����һ���--ؤ������á��ƹ������أ����Ǵ����Ĵ��š�ֻ������
��ִ���ȡ����������һ����ؤ�����վ�ڴ�����ǰ�����ࡣ
LONG
  );
  	set("exits",([
	         "north":__DIR__"gb4",
	         "south":__DIR__"shungeng",
	         "west":__DIR__"gb3",
	         "east":__DIR__"gb2"
               ]));
    	set("outdoors", "jinan");
        set("coor/x",-20);
        set("coor/y",90);
        set("coor/z",0);
    	set("resource/water", 1);
    	set("liquid/container", "������");    
    	set("liquid/name","������ˮ");
	setup();
}