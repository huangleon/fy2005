// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����Ժ");
        set("long", @LONG
���������������������⣬������λ���³��ϣ��书������ߣ��ҷ𷨾��
�ĳ���ִ��ɮ�࣬ά�����ְ�ȫ�����������ֲ��ڷ���֮�£��ݴ���������λ����
������ǧ�������ɫ����λ������ʮ�������������ӳ�����ɮ�ࡣ
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jian",
  "southeast" : __DIR__"laos",
  "northeast": __DIR__"laon",
  "west":__DIR__"banruo",
]));
        set("objects", ([
                __DIR__"npc/master_17_6" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}

/*void init()
{
        if(this_player()->query_skill("daode",1) >= 10)
	set("exits/west",__DIR__"banruo");
	else
	delete("exits/west");

}*/


int valid_leave(object me,string dir)
{
    object ob;
	
	if(userp(me) && dir == "west" && ob=present("master deng",this_object()))
	{
		if (me->query_skill("daode",1)<10){
			message_vision("�ĵƶ�$N˵���㻹����ѧ����¾��ɡ�\n",this_player());
			return notify_fail("");
		}	
	}
	return 1;
}
