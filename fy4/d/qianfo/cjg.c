inherit DOOR_ROOM;
#include <room.h>

void create()
{
  	set("short","�ؾ���");
  	set("long",@LONG
����������飬�����޾��ľ��飬�ıں����붼�������ݶ��ĺ�ľ��ܣ�����
�м�����������ţ�������ü�׷�����ɮ����������ѷ��ѵ��ڴ������������⣬
��ֻ�м�����̨����֧������ɢ�����鰸�ϡ�
LONG
  );
  	set("exits",([
         	"down":	__DIR__"mishi1",
               ]));
        set("objects", ([
                __DIR__"npc/bonze_h1" : 1,
                __DIR__"npc/bonze_h2" : 1,
                __DIR__"npc/bonze_h3" : 1,
       	]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	
}



void reset() {
	string *item= ({"force_75","force_75a","force_75b","force_75c","force_75d" });
	object ob;
	
	:: reset();
	
	foreach (string x in item) 
	{
		ob = new(BOOKS+x);
		if (present(ob,this_object())) destruct(ob);
			else ob->move(this_object());
	}
}

