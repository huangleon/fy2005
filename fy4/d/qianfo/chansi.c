//mac's chansi.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","�˹�����");
  set("long",@LONG
��ʯ�����ɽ���Ͽ��ţ�[33m�˹�����[32m������Ʈ������������õ�ɽ��������;���
һ�񣬻ص����ӹ�֮���ָ���һ�����µĸо���ɽ�����ԵĶ�����������עĿ��
[0;1;31m
		ĺ�ĳ���  ��������������
		�������  ���ؿຣ������		
[0m
LONG
  );
        set("objects", ([
                __DIR__"npc/bonze2" : 2,
		__DIR__"npc/greeting" : 2,
       	]) );
  	set("exits",([
         	"southdown":__DIR__"fudi.c",
         	"north"    :__DIR__"jinggang.c"
       ]));
   
        set("outdoors", "qianfo");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
