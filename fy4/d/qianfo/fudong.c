//mac's fudong.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","ǧ����");
  set("long",@LONG
��Ժ�ϲ��ͱڶ������׳ơ�ǧ���¡����ֲ����忪ͽ�����Ħ��������ʮ����
��������Ȫ�����֡�ǭ¦����������д�С����ǧ��ɽ����³��������ں��ͱ�
�ϵķ�������ǧ�������ڷ���Բ�Ϫ���ܺ���ͽֻ�Ե������ܣ����Ҿ�Ѩ������
��Լ�������³���ʱʼ��ľ��ҡ�
LONG
  );
  	set("exits",([
        	 "west" :__DIR__"jinggang",
        	 "north":__DIR__"changlang2",
       	]));
        set("objects", ([
        	 __DIR__"npc/master3" : 1,
       	]) ); 
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
