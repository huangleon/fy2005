#include <room.h>  
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
��ɴ�й��߻����������뵣�һλ������ϥ��������֮�ϡ����ű���һ��¯��
���ƴ���¯��ȽȽ���𣬳������������䡣

LONG
  );
  	set("exits/out" ,__DIR__"outboat");
    set("objects",([
    	__DIR__"npc/jiayi" : 1,
		__DIR__"obj/coffin": 1,
    ]) );

	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
	
 }



int reset(){
	object coffin;
	
	coffin = present("coffin", this_object());
	if (coffin)
	if (!random(10) && coffin->query_temp("been_get"))
		coffin->delete_temp("been_get");
		
	::reset();
}