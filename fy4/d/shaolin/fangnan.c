// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������Ժ");
        set("long", @LONG
���������Ѿ�û����ס�ˣ���������ī�ͣ���ѧ̩�����ͷ���֮������ڴˣ�
�������Բ̾��ġ���������Ϊ���ڡ�
LONG
        );
        set("exits", ([ 
		  "southup" : __DIR__"changjing",
		  "northup" : __DIR__"lixue",
]));
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
}


void init ()
{

   	add_action("do_north", "go");

}

int do_north(string arg)
{
   	object me, room;
   	me = this_player();
	if (arg == "north")
	if(me->query_temp("see_fangzhang")) {
		room = find_object(__DIR__"fang");
   		if(!objectp(room)) room=load_object(__DIR__"fang");
      		message("vision", me->name()+"���뿪��\n", environment(me),me );
   		me->move(room);
   		message("vision", me->name()+"���˹�����\n", environment(me),me );
   		return 1;
   	}
   	return 0;
}


/*
void init()
{
	if(!this_player()->query_temp("see_fangzhang"))
	{
		set("exits/northup",__DIR__"lixue");
		delete("exits/north");
	}
	else 
	{
		set("exits/north", __DIR__"fang");
		delete("exits/northup");
	}
}*/
