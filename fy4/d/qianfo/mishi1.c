inherit DOOR_ROOM;
#include <room.h>

void create()
{
  	set("short","���߸�");
  	set("long",@LONG
¥�ϱ����˹����µĸ�ɮ���ж�����ĵط��������������������������С��
��ææµµ����ʰ�ţ����Ǵ���Ǹ����˼ҵ��ӵܣ�Ľ�����µ�����ǰ��Ͷ������
����ʦ�����Ƿ��ɵ������ɨ����˵����ĥ���������ĸ���֮����
LONG
  );
  	set("exits",([
         	"south":__DIR__"yezhang",
         	"up":	__DIR__"cjg",
               ]));
        set("objects", ([
                __DIR__"npc/bonze_j1" : 1,
                __DIR__"npc/bonze_j2" : 1,
       	]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	create_door("south","door","ʯ��","north",DOOR_CLOSED);
}


/*
void reset() {
	string *item= ({"book1","book2","book3","book4","book5" });
	object ob;
	
	:: reset();
	
	foreach (string x in item) 
	{
		ob = new(__DIR__"obj/"+x);
		if (present(ob,this_object())) destruct(ob);
			else ob->move(this_object());
	}
}


*/	
	