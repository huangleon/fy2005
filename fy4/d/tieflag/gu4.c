// Room: dong0
inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "С��");
        set("long", @LONG
һ����ɫ��ʯС��ֱͨ���ᣬ���������ʻ�������ͷס�·�߸��и��ֹ�����
������͸����Ϊ���ˡ�һ�������������·���ɰ���
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
 		 "eastup" : __DIR__"gu3",
  		"westdown" : __DIR__"gu5",
 
	]));
	set("outdoors","tieflag"); 	
   	create_door("westdown","door","����","eastup",DOOR_CLOSED);         
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",20);
	setup();

}
void init()
{
	add_action("do_get","pick");
} 	  

int do_get(string arg)
{
        object swo;
	if( query("mark/been_get")>10) return notify_fail("�����ѱ�ժ���ˡ�\n");
        if(random(1000)>1) 
        { 
		swo=new(__DIR__"obj/yiguo");
		swo->move(this_player());
		add("mark/been_get",1);
		write("�������ժ��һ�����ӡ�\n" );
	}
	else
        { 
		swo=new(__DIR__"obj/yiguo1");
		swo->move(this_player());
		add("mark/been_get",1);
		write("�������ժ��һ������. \n" );
	}
        
        return 1;

}
void reset()
{
    	::reset();
	delete("mark/been_get");
}
