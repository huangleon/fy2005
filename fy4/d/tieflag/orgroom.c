#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",HIY "����"NOR);
  set("long",@LONG
�����ֱ����һ�Ҿ�¥������Ӧ��˵�Ǿ�¥�������ң�ǽ�Ϲ����˽�Ƶ��ռ���
���죬��Ѽ������˵�������ռ��ĵط�Ӧ�úܳ����������ﲻ�������������л�Ʈ
�����Ƶ���������������ǽ�ǵ�һֻ��ľͰ������˵������װ��һ������һ��ľ�
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/orggirl" : 1,
       ]) );
  
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
 }
