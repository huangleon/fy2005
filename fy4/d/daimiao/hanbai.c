
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","����Ժ");
  	set("long",@LONG
����Ժ�������������������������ƴ��ң����顰�����š�����Ժ��ԭ�б���
��ڹ�̩ɽ�����̫�ӱ����������������⣬Ժ�ڻ��йŰ����꣬��Ϊ����۶�
��ʱ��ֲ�����Դ�Ժ�ɳơ����鹬������ơ�����Ժ����
LONG
  );
  	set("exits",([
         	"west":__DIR__"sanling",
         	"north": __DIR__"hanbaiting",
         	"south": __DIR__"linghan",
        ]));
        set("objects", ([
        	__DIR__"npc/tian":	1,
        
       	]) );
	set("coor/x",20);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
