
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�ʰ���");
  set("long",@LONG
�ʰ��ţ�ȡ�Կ��ӡ����߰��ʡ�֮�⡣����ԭ��������������֮�������Ƕ�
�������������ʰ�֮�ţ���ͨ��������ǰ��ͭʨ���У�����ʯʨ�������������
����Կ������հ�������ܵ���Զ����ΰ��̩ɽ�ĳ���֮�£��Ե�����׳�ۡ�
LONG
  );
  	set("exits",([
         	"north":__DIR__"gelaochi",
         	"south":__DIR__"peitian.c",
         	"east" :__DIR__"dongyu.c",
         	"west" :__DIR__"chuxun.c",
        ]));
        set("objects", ([
        	__DIR__"npc/guard3":	2,
        
       	]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
